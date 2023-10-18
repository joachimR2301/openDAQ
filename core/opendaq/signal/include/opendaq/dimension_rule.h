/*
 * Copyright 2022-2023 Blueberry d.o.o.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <coretypes/dictobject.h>
#include <coretypes/number.h>

BEGIN_NAMESPACE_OPENDAQ

/*!
 * @ingroup opendaq_dimension
 * @addtogroup opendaq_dimension_rule Dimension rule
 * @{
 */

/*!
 * @brief Enumeration of available rule types
 */
enum class DimensionRuleType
{
    Other = 0,   ///< The rule is unknown to openDAQ and cannot be handled automatically.
    Linear,      ///< The parameters contain a `delta`, `start`, and `size` parameters member. Calculated as: <em>index * delta + start</em> for `size` number of elements.
    Logarithmic, ///< The parameters contain a `delta`, `start`, `base`, and `size` parameters member. Calculated as: <em>base ^ (index * delta + start)</em> for `size` number of elements.
    List         ///< The parameters contain a `list` parameters member. The list contains all dimension labels.
};

/*!
 * @brief Rule that defines the labels (alternatively called bins, ticks) of a dimension.
 *
 * Each dimension has a rule, which is queried and parsed by the dimension `getLabels` and `getSize` calls.
 * Three different rule types are supported by openDAQ, with all others having to be set to `custom` type, requiring
 * anyone using them to parse them manually.
 *
 * Dimension rule objects implement the Struct methods internally and are Core type `ctStruct`.
 * 
 * @subsection dimension_rule_types Rule types
 * @subsubsection linear_dimension_rule Linear dimension rule
 * The parameters include a `delta`, `start`, and `size` integer members. The list of labels of size `size` is generated by
 * the equation: <em>index * delta + start</em>, where the index starts with 0 and goes up to `size - 1`.
 *
 * In example: `delta = 10, start = 5, size = 5` produces the following list of samples -> [5, 15, 25, 35, 45] 
 *
 * @subsubsection logarithmic_dimension_rule Logarithmic dimension rule
 * The parameters include a `delta`, `start`, `base` and `size` integer members. The list of labels of size `size` is generated by
 * the equation: <em>base ^ (index * delta + start)</em>, where the index starts with 0 and goes up to `size - 1`.
 *
 * In example: `delta = 1, start = -2, base = 10 size = 5` produces the following list of samples -> [0.01, 0.1, 1, 10, 20]
 *
 * @subsubsection list_dimension_rule List dimension rule
 * The parameters include a `list` list-typed member. The `list` contains labels, implicitly also defining the dimension size.
 * The labels in the list can be either strings, numbers, or ranges.
 *
 * String example list: `list` = ["banana", "apple", "coconut"]
 * Number example list: = [1.2, 10.5, 20.2, 50.7]
 * Range example list: [1-10, 10-20, 20-30, 30-40, 40-50]
 */
DECLARE_OPENDAQ_INTERFACE(IDimensionRule, IBaseObject)
{
    /*!
     * @brief Gets the type of the dimension rule.
     * @param[out] type The type of the dimension rule.
     */
    virtual ErrCode INTERFACE_FUNC getType(DimensionRuleType* type) = 0;

    // [templateType(parameters, IString, IBaseObject)]
    /*!
     * @brief Gets a dictionary of string-object key-value pairs representing the parameters used to evaluate the rule.
     * @param[out] parameters The dictionary containing the rule parameter members.
     */
    virtual ErrCode INTERFACE_FUNC getParameters(IDict** parameters) = 0;
};
/*!@}*/

/*!
 * @ingroup opendaq_dimension_rule
 * @addtogroup opendaq_dimension_rule_factories Factories
 * @{
 */

/*!
 * @brief Creates a Rule with a Linear rule type configuration.
 *
 * @param delta Coefficient by which the input data is to be multiplied.
 * @param start Constant that is added to the <em>scale * value</em> multiplication result.
 * @param size The size of the dimension described by the rule
 *
 * The scale and offset are stored within the `parameters` member of the Rule object
 * with the scale being at the first position of the list, and the offset at the second.
 */
OPENDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, LinearDimensionRule, IDimensionRule,
    INumber*, delta,
    INumber*, start,
    SizeT, size
)

/*!
 * @brief Creates a Rule with a List rule type configuration.
 *
 * @param list The list of dimension labels.
 *
 * The list is stored within the `parameters` member of the Rule object.
 */
OPENDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, ListDimensionRule, IDimensionRule,
    IList*, list
)

/*!
 * @brief Creates a Rule with a Logarithmic rule type configuration.
 *
 * @param delta Coefficient by which the input data is to be multiplied.
 * @param start Constant that is added to the <em>scale * value</em> multiplication result.
 * @param base The base of the logarithm.
 * @param size The size of the dimension described by the rule.
 */
OPENDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, LogarithmicDimensionRule, IDimensionRule,
    INumber*, delta,
    INumber*, start,
    INumber*, base,
    SizeT, size
)

/*!
 * @brief Creates a Rule with a given type and parameters.
 *
 * @param type The type of the Dimension rule
 * @param parameters Tha parameters of the Dimension rule
 */
OPENDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, DimensionRule, IDimensionRule,
    DimensionRuleType, type,
    IDict*, parameters
)

/*!@}*/

END_NAMESPACE_OPENDAQ