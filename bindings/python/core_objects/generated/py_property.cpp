//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (PythonGenerator).
// </auto-generated>
//------------------------------------------------------------------------------

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

#include "py_core_objects/py_core_objects.h"
#include "py_core_types/py_converter.h"

PyDaqIntf<daq::IProperty, daq::IBaseObject> declareIProperty(pybind11::module_ m)
{
    return wrapInterface<daq::IProperty, daq::IBaseObject>(m, "IProperty");
}

void defineIProperty(pybind11::module_ m, PyDaqIntf<daq::IProperty, daq::IBaseObject> cls)
{
    cls.doc() = "Defines a set of metadata that describes the values held by a Property object stored under the key equal to the property's name.";

    m.def("BoolProperty", &daq::BoolProperty_Create);
    m.def("IntProperty", &daq::IntProperty_Create);
    m.def("FloatProperty", &daq::FloatProperty_Create);
    m.def("StringProperty", &daq::StringProperty_Create);
    m.def("ListProperty", &daq::ListProperty_Create);
    m.def("DictProperty", &daq::DictProperty_Create);
    m.def("RatioProperty", &daq::RatioProperty_Create);
    m.def("ObjectProperty", &daq::ObjectProperty_Create);
    m.def("ReferenceProperty", &daq::ReferenceProperty_Create);
    m.def("FunctionProperty", &daq::FunctionProperty_Create);
    m.def("SelectionProperty", &daq::SelectionProperty_Create);
    m.def("SparseSelectionProperty", &daq::SparseSelectionProperty_Create);
    m.def("StructProperty", &daq::StructProperty_Create);
    m.def("PropertyFromBuildParams", &daq::PropertyFromBuildParams_Create);

    cls.def_property_readonly("value_type",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getValueType();
        },
        "Gets the Value type of the Property. Values written to the corresponding Property value must be of the same type.");
    cls.def_property_readonly("key_type",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getKeyType();
        },
        "Gets the Key type of the Property. Configured only if the Value type is `ctDict`. If so, the key type of the dictionary Property values must match the Property's Key type.");
    cls.def_property_readonly("item_type",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getItemType();
        },
        "Gets the Item type of the Property. Configured only if the Value type is `ctDict` or `ctList`. If so, the item types of the list/dictionary must match the Property's Item type.");
    cls.def_property_readonly("name",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getName().toStdString();
        },
        "Gets the Name of the Property. The names of Properties in a Property object must be unique. The name is used as the key to the corresponding Property value when getting/setting the value.");
    cls.def_property_readonly("description",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getDescription().toStdString();
        },
        "Gets the short string Description of the Property.");
    cls.def_property_readonly("unit",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getUnit().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the Unit of the Property.");
    cls.def_property_readonly("min_value",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getMinValue().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the Minimum value of the Property. Available only if the Value type is `ctInt` or `ctFloat`.");
    cls.def_property_readonly("max_value",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getMaxValue().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the Maximum value of the Property. Available only if the Value type is `ctInt` or `ctFloat`.");
    cls.def_property_readonly("default_value",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return baseObjectToPyObject(objectPtr.getDefaultValue());
        },
        py::return_value_policy::take_ownership,
        "Gets the Default value of the Property. The Default value must always be configured for a Property to be in a valid state. Exceptions are Function/Procedure and Reference properties.");
    cls.def_property_readonly("suggested_values",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getSuggestedValues().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the list of Suggested values. Contains values that are the optimal settings for the corresponding Property value. These values, however, are not enforced when setting a new Property value.");
    cls.def_property_readonly("visible",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getVisible();
        },
        "Used to determine whether the property is visible or not.");
    cls.def_property_readonly("read_only",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getReadOnly();
        },
        "Used to determine whether the Property is a read-only property or not.");
    cls.def_property_readonly("selection_values",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return baseObjectToPyObject(objectPtr.getSelectionValues());
        },
        py::return_value_policy::take_ownership,
        "Gets the list or dictionary of selection values. If the list/dictionary is not empty, the property is a Selection property, and must have the Value type `ctInt`.");
    cls.def_property_readonly("referenced_property",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getReferencedProperty().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the referenced property. If set, all getters except for the `Name`, `Referenced property`, and `Is referenced` getters will return the value of the `Referenced property`.");
    cls.def_property_readonly("is_referenced",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getIsReferenced();
        },
        "Used to determine whether the Property is referenced by another property.");
    cls.def_property_readonly("validator",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getValidator().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the validator of the Property.");
    cls.def_property_readonly("coercer",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getCoercer().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the coercer of the Property.");
    cls.def_property_readonly("callable_info",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getCallableInfo().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the Callable information objects of the Property that specifies the argument and return types of the callable object stored as the Property value.");
    cls.def_property_readonly("struct_type",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getStructType().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the Struct type object of the Property, if the Property is a Struct property.");
    /*
    cls.def_property_readonly("on_property_value_write",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getOnPropertyValueWrite().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the event object that is triggered when a value is written to the corresponding Property value.");
    */
    /*
    cls.def_property_readonly("on_property_value_read",
        [](daq::IProperty *object)
        {
            const auto objectPtr = daq::PropertyPtr::Borrow(object);
            return objectPtr.getOnPropertyValueRead().detach();
        },
        py::return_value_policy::take_ownership,
        "Gets the event object that is triggered when the corresponding Property value is read.");
    */
}