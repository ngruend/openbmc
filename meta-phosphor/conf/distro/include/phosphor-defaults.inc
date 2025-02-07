OBMC_BMC_INSTANCES ?= "0"
OBMC_CHASSIS_INSTANCES ?= "0"
OBMC_CHECKSTOP_INSTANCES ?= "0"
OBMC_FAN_INSTANCES ?= ""
OBMC_HOST_INSTANCES ?= "0"
OBMC_POWER_BUTTON_INSTANCES ?= "0"
OBMC_POWER_INSTANCES ?= "0"
OBMC_RESET_BUTTON_INSTANCES ?= "0"
OBMC_WATCHDOG_INSTANCES ?= "0"

PREFERRED_PROVIDER_virtual/obmc-chassis-mgmt ?= "obmc-phosphor-chassisd"
PREFERRED_PROVIDER_virtual/obmc-event-mgmt ?= "obmc-phosphor-event"
PREFERRED_PROVIDER_virtual/obmc-fan-mgmt ?= "obmc-phosphor-fand"
PREFERRED_PROVIDER_virtual/obmc-flash-mgmt ?= "obmc-phosphor-flashd"
PREFERRED_PROVIDER_virtual/obmc-host-ipmi-hw ?= "phosphor-ipmi-hw-example"

# obmc-bmc-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.BMC
# interface.
VIRTUAL-RUNTIME_obmc-bmc-state-manager ?= "phosphor-state-manager-bmc"

# obmc-chassis-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.Chassis
# interface.
VIRTUAL-RUNTIME_obmc-chassis-state-manager ?= "phosphor-state-manager-chassis"

# obmc-host-state-manager
#
# Provides an implementation of the xyz.openbmc_project.State.Host
# interface.
VIRTUAL-RUNTIME_obmc-host-state-manager ?= "phosphor-state-manager-host"

# obmc-discover-system-state
#
# Provides an implementation of phosphor-discover-system-state, which, if the
# host is powered off, will check the current power policy and, if necessary,
# power the host back on.
VIRTUAL-RUNTIME_obmc-discover-system-state ?= "phosphor-state-manager-discover"

# obmc-host-check
#
# Provides an implementation of phosphor-host-check, which will determine
# if the host is running after a BMC reboot and create the necessary file
# to indicate to host services that the host is running
VIRTUAL-RUNTIME_obmc-host-check ?= "phosphor-state-manager-host-check"

# obmc-fan-presence
#
# Provides implementations of fan presence detection
VIRTUAL-RUNTIME_obmc-fan-presence ?= "phosphor-fan-presence-tach"

# obmc-fan-control
#
# Provides implementations of fan control
VIRTUAL-RUNTIME_obmc-fan-control ?= "phosphor-fan-control"

# obmc-inventory-manager
#
# Provides an implementation of the xyz.openbmc_project.Inventory.Manager
# interface.
VIRTUAL-RUNTIME_obmc-inventory-manager ?= "phosphor-inventory-manager"

# obmc-led-manager
#
# Provides an implementation of the xyz.openbmc_project.ledmanager interface.
VIRTUAL-RUNTIME_obmc-leds-manager ?= "phosphor-led-manager-ledmanager"

# obmc-led-monitor
#
# Provides an implementation of the FRU fault monitor.
VIRTUAL-RUNTIME_obmc-led-monitor ?= "phosphor-led-manager-faultmonitor"

# obmc-led-sysfs
#
# Provides an implementation of xyz.openbmc_project.Led.Physical for
# Linux kernel LED subsystem LEDs.
VIRTUAL-RUNTIME_obmc-leds-sysfs ?= "phosphor-led-sysfs"

# obmc-bmc-code-mgr
#
# Provides an implementation of the xyz.openbmc_project.Software.BMC.Version
# interface.
VIRTUAL-RUNTIME_obmc-bmc-code-mgr ?= "phosphor-software-manager-version"

# obmc-bmc-download-mgr
#
# Provides an implementation of the xyz.openbmc_project.Common.TFTP
# interface.
VIRTUAL-RUNTIME_obmc-bmc-download-mgr ?= "phosphor-software-manager-download-mgr"

PREFERRED_PROVIDER_virtual/obmc-logging-mgmt ?= "phosphor-logging"
PREFERRED_PROVIDER_virtual/obmc-net-ipmi ?= "phosphor-ipmi-net"

# obmc-sensors-hwmon
#
# Provides an implementation of xyz.openbmc_project.Sensor.Value
# for hwmon sensors.
VIRTUAL-RUNTIME_obmc-sensors-hwmon ?= "phosphor-hwmon"

# obmc-debug-collector
# The phosphor-debug-collector used for collecting and managing dumps
VIRTUAL-RUNTIME_obmc-debug-collector ?= "phosphor-debug-collector"

PREFERRED_PROVIDER_virtual/obmc-settings-mgmt ?= "phosphor-settings"
PREFERRED_PROVIDER_virtual/obmc-system-mgmt ?= "obmc-phosphor-sysd"
PREFERRED_PROVIDER_virtual/obmc-user-mgmt ?= "obmc-phosphor-user"
PREFERRED_PROVIDER_virtual/obmc-wsgihost ?= "phosphor-gevent"

# phosphor-hwmon-config
#
# The phosphor-hwmon package can have its configuration generated
# automatically if the MRW feature is enabled.
VIRTUAL-RUNTIME_phosphor-hwmon-config ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-hwmon-config-mrw')}"

# virtual/phosphor-ipmi-fru-hostfw-config
#
# The phosphor-ipmi-fru application is data-driven and requires an input
# mapping of how the host firmware reports inventory via IPMI.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-ipmi-fru build process.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-hostfw-config ?= "phosphor-ipmi-fru-hostfw-config-example-native"

# The phosphor-ipmi-fru application is data-driven and requires an input
# mapping of IPMI inventory metadata to DBus objects interfaces and properties.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-ipmi-fru build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-inventory ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-fru-inventory-mrw-native', 'phosphor-ipmi-fru-inventory-example-native')}"
PREFERRED_PROVIDER_virtual/phosphor-ipmi-fru-properties ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-fru-properties-mrw-native', 'phosphor-ipmi-fru-properties-native')}"

# The phosphor-led-manager application is data-driven and requires an input
# yaml of LED group and members.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-led-manager build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-led-manager-config-native ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-led-manager-config-mrw-native', 'phosphor-led-manager-config-example-native')}"

# The phosphor-host-ipmid application is data-driven and requires an input
# mapping of IPMI inventory sensor metadata to DBus objects interfaces and properties.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-host-ipmid build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-sensor-inventory ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-sensor-inventory-mrw-native', 'phosphor-ipmi-sensor-inventory-native')}"

# The phosphor-logging application has a data driven plugin that adds FRU
# callout information to error logs, when applications generating error logs
# add the requisite callout metadata to the systemd journal.  The plugin requires
# an input mapping of Linux sysfs devices to OpenBMC DBus objects.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-logging build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-logging-callouts ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-logging-callouts-mrw-native', 'phosphor-logging-callouts-example-native')}"

# The phosphor-fan-presence application is data driven and requires an
# input YAML that maps fans to their tach sensors.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-fan-presence build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-fan-presence-config ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-fan-presence-mrw-native', 'phosphor-fan-presence-example-native')}"

# The phosphor-fan-control application is data driven and requires a YAML
# file to define the fans in the system.
# This virtual is a native recipe that provides that definition by installing
# the YAML file in the format and native sysroot location expected by
# the phosphor-fan-control build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-fan-control-fan-config ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-fan-control-fan-config-mrw-native', 'phosphor-fan-control-fan-config-native')}"

# The phosphor-host-ipmid application is data-driven and requires an input
# mapping of inventory object path to the sensor number and sensor metadata.
# This virtual is a native recipe that provides that mapping by installing
# configuration files in the format and native sysroot location expected by
# the phosphor-host-ipmid build process in the native sysroot.
PREFERRED_PROVIDER_virtual/phosphor-ipmi-inventory-sel ?= \
    "${@cf_enabled(d, 'obmc-mrw', 'phosphor-ipmi-inventory-sel-mrw-native', 'phosphor-ipmi-inventory-sel-native')}"

OBMC_DBUS_PATH_ROOT ?= "/xyz/openbmc_project"
OBMC_DBUS_IFACE_ROOT ?= "xyz.openbmc_project"
