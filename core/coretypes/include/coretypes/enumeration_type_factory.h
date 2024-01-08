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
#include <coretypes/enumeration_type_ptr.h>
#include <coretypes/listobject_factory.h>

BEGIN_NAMESPACE_OPENDAQ

/*!
 * @ingroup types_enumerations_enumeration
 * @defgroup types_enumerations_enumeration_factories Factories
 * @{
 */

/*!
 * @brief Creates an Enumeration type with a given type name, enumerator names and first enumerator value.
 * Enumerator values are automatically assigned in ascending order, starting from the specified first value.
 * @param typeName The name of the Enumeration type
 * @param enumeratorNames The list of enumerator names (String objects)
 * @param firstEnumeratorValue The value of first enumerator (Integer)
 */
inline EnumerationTypePtr EnumerationType(
    const StringPtr& typeName,
    const ListPtr<IString>& enumeratorNames,
    const Int firstEnumeratorValue = 0)
{
    EnumerationTypePtr obj(EnumerationType_Create(typeName, enumeratorNames, firstEnumeratorValue));
    return obj;
}

/*!
 * @brief Creates an Enumeration type for enum with a given type name, enumerator names and
 * specified enumerator values.
 * @param typeName The name of the Enumeration type
 * @param enumeratorNames The list of enumerator names (String objects)
 * @param enumeratorValues The list of enumerator values (Integer objects)
 *
 * The lists of enumerator names and values must be of equal size.
 */
inline EnumerationTypePtr EnumerationType(
    const StringPtr& typeName,
    const ListPtr<IString>& enumeratorNames,
    const ListPtr<IInteger>& enumeratorValues)
{
    EnumerationTypePtr obj(EnumerationTypeWithValues_Create(typeName, enumeratorNames, enumeratorValues));
    return obj;
}

/*!@}*/
END_NAMESPACE_OPENDAQ
