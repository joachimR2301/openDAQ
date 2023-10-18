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
 * Blueberry d.o.o. ("COMPANY") CONFIDENTIAL
 * Unpublished Copyright (c) 2022-2023 Blueberry d.o.o., All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * COMPANY. The intellectual and technical concepts contained herein are
 * proprietary to COMPANY and are protected by copyright law and as trade
 * secrets and may also be covered by U.S. and Foreign Patents, patents in
 * process, etc.
 * Dissemination of this information or reproduction of this material is
 * strictly forbidden unless prior written permission is obtained from COMPANY.
 * Access to the source code contained herein is hereby forbidden to anyone
 * except current COMPANY employees, managers or contractors who have executed
 * Confidentiality and Non-disclosure agreements explicitly covering such
 * access.
 *
 * The copyright notice above does not evidence any actual or intended
 * publication or disclosure  of  this source code, which includes information
 * that is confidential and/or proprietary, and is a trade secret of COMPANY.
 * ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC PERFORMANCE, OR PUBLIC
 * DISPLAY OF OR THROUGH USE OF THIS SOURCE CODE WITHOUT THE EXPRESS
 * WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF
 * APPLICABLE LAWS AND INTERNATIONAL TREATIES. THE RECEIPT OR POSSESSION OF
 * THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY
 * RIGHTS TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE,
 * USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
 */

#include "py_opendaq/py_opendaq.h"
#include "py_core_types/py_converter.h"

PyDaqIntf<daq::IPacketDestructCallback, daq::IBaseObject> declareIPacketDestructCallback(pybind11::module_ m)
{
    return wrapInterface<daq::IPacketDestructCallback, daq::IBaseObject>(m, "IPacketDestructCallback");
}

void defineIPacketDestructCallback(pybind11::module_ m, PyDaqIntf<daq::IPacketDestructCallback, daq::IBaseObject> cls)
{
    cls.doc() = "Used to subscribe to packet destruction";

    cls.def("on_packet_destroyed",
        [](daq::IPacketDestructCallback *object)
        {
            const auto objectPtr = daq::PacketDestructCallbackPtr::Borrow(object);
            objectPtr.onPacketDestroyed();
        },
        "Called when packet is destroyed.");
}