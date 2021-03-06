# Linux ethtool命令详解

## 用法usage

```bash
ethtool version 4.15
Usage:
        ethtool DEVNAME	Display standard information about device
        ethtool -s|--change DEVNAME	Change generic options
		[ speed %d ]
		[ duplex half|full ]
		[ port tp|aui|bnc|mii|fibre ]
		[ mdix auto|on|off ]
		[ autoneg on|off ]
		[ advertise %x ]
		[ phyad %d ]
		[ xcvr internal|external ]
		[ wol p|u|m|b|a|g|s|d... ]
		[ sopass %x:%x:%x:%x:%x:%x ]
		[ msglvl %d | msglvl type on|off ... ]
        ethtool -a|--show-pause DEVNAME	Show pause options
        ethtool -A|--pause DEVNAME	Set pause options
		[ autoneg on|off ]
		[ rx on|off ]
		[ tx on|off ]
        ethtool -c|--show-coalesce DEVNAME	Show coalesce options
        ethtool -C|--coalesce DEVNAME	Set coalesce options
		[adaptive-rx on|off]
		[adaptive-tx on|off]
		[rx-usecs N]
		[rx-frames N]
		[rx-usecs-irq N]
		[rx-frames-irq N]
		[tx-usecs N]
		[tx-frames N]
		[tx-usecs-irq N]
		[tx-frames-irq N]
		[stats-block-usecs N]
		[pkt-rate-low N]
		[rx-usecs-low N]
		[rx-frames-low N]
		[tx-usecs-low N]
		[tx-frames-low N]
		[pkt-rate-high N]
		[rx-usecs-high N]
		[rx-frames-high N]
		[tx-usecs-high N]
		[tx-frames-high N]
		[sample-interval N]
        ethtool -g|--show-ring DEVNAME	Query RX/TX ring parameters
        ethtool -G|--set-ring DEVNAME	Set RX/TX ring parameters
		[ rx N ]
		[ rx-mini N ]
		[ rx-jumbo N ]
		[ tx N ]
        ethtool -k|--show-features|--show-offload DEVNAME	Get state of protocol offload and other features
        ethtool -K|--features|--offload DEVNAME	Set protocol offload and other features
		FEATURE on|off ...
        ethtool -i|--driver DEVNAME	Show driver information
        ethtool -d|--register-dump DEVNAME	Do a register dump
		[ raw on|off ]
		[ file FILENAME ]
        ethtool -e|--eeprom-dump DEVNAME	Do a EEPROM dump
		[ raw on|off ]
		[ offset N ]
		[ length N ]
        ethtool -E|--change-eeprom DEVNAME	Change bytes in device EEPROM
		[ magic N ]
		[ offset N ]
		[ length N ]
		[ value N ]
        ethtool -r|--negotiate DEVNAME	Restart N-WAY negotiation
        ethtool -p|--identify DEVNAME	Show visible port identification (e.g. blinking)
               [ TIME-IN-SECONDS ]
        ethtool -t|--test DEVNAME	Execute adapter self test
               [ online | offline | external_lb ]
        ethtool -S|--statistics DEVNAME	Show adapter statistics
        ethtool --phy-statistics DEVNAME	Show phy statistics
        ethtool -n|-u|--show-nfc|--show-ntuple DEVNAME	Show Rx network flow classification options or rules
		[ rx-flow-hash tcp4|udp4|ah4|esp4|sctp4|tcp6|udp6|ah6|esp6|sctp6 |
		  rule %d ]
        ethtool -N|-U|--config-nfc|--config-ntuple DEVNAME	Configure Rx network flow classification options or rules
		rx-flow-hash tcp4|udp4|ah4|esp4|sctp4|tcp6|udp6|ah6|esp6|sctp6 m|v|t|s|d|f|n|r... |
		flow-type ether|ip4|tcp4|udp4|sctp4|ah4|esp4|ip6|tcp6|udp6|ah6|esp6|sctp6
			[ src %x:%x:%x:%x:%x:%x [m %x:%x:%x:%x:%x:%x] ]
			[ dst %x:%x:%x:%x:%x:%x [m %x:%x:%x:%x:%x:%x] ]
			[ proto %d [m %x] ]
			[ src-ip IP-ADDRESS [m IP-ADDRESS] ]
			[ dst-ip IP-ADDRESS [m IP-ADDRESS] ]
			[ tos %d [m %x] ]
			[ tclass %d [m %x] ]
			[ l4proto %d [m %x] ]
			[ src-port %d [m %x] ]
			[ dst-port %d [m %x] ]
			[ spi %d [m %x] ]
			[ vlan-etype %x [m %x] ]
			[ vlan %x [m %x] ]
			[ user-def %x [m %x] ]
			[ dst-mac %x:%x:%x:%x:%x:%x [m %x:%x:%x:%x:%x:%x] ]
			[ action %d ]
			[ loc %d]] |
		delete %d
        ethtool -T|--show-time-stamping DEVNAME	Show time stamping capabilities
        ethtool -x|--show-rxfh-indir|--show-rxfh DEVNAME	Show Rx flow hash indirection table and/or RSS hash key
        ethtool -X|--set-rxfh-indir|--rxfh DEVNAME	Set Rx flow hash indirection table and/or RSS hash key
		[ equal N | weight W0 W1 ... | default ]
		[ hkey %x:%x:%x:%x:%x:.... ]
		[ hfunc FUNC ]
        ethtool -f|--flash DEVNAME	Flash firmware image from the specified file to a region on the device
               FILENAME [ REGION-NUMBER-TO-FLASH ]
        ethtool -P|--show-permaddr DEVNAME	Show permanent hardware address
        ethtool -w|--get-dump DEVNAME	Get dump flag, data
		[ data FILENAME ]
        ethtool -W|--set-dump DEVNAME	Set dump flag of the device
		N
        ethtool -l|--show-channels DEVNAME	Query Channels
        ethtool -L|--set-channels DEVNAME	Set Channels
               [ rx N ]
               [ tx N ]
               [ other N ]
               [ combined N ]
        ethtool --show-priv-flags DEVNAME	Query private flags
        ethtool --set-priv-flags DEVNAME	Set private flags
		FLAG on|off ...
        ethtool -m|--dump-module-eeprom|--module-info DEVNAME	Query/Decode Module EEPROM information and optical diagnostics if available
		[ raw on|off ]
		[ hex on|off ]
		[ offset N ]
		[ length N ]
        ethtool --show-eee DEVNAME	Show EEE settings
        ethtool --set-eee DEVNAME	Set EEE settings
		[ eee on|off ]
		[ advertise %x ]
		[ tx-lpi on|off ]
		[ tx-timer %d ]
        ethtool --set-phy-tunable DEVNAME	Set PHY tunable
		[ downshift on|off [count N] ]
        ethtool --get-phy-tunable DEVNAME	Get PHY tunable
		[ downshift ]
        ethtool --reset DEVNAME	Reset components
		[ flags %x ]
		[ mgmt ]
		[ mgmt-shared ]
		[ irq ]
		[ irq-shared ]
		[ dma ]
		[ dma-shared ]
		[ filter ]
		[ filter-shared ]
		[ offload ]
		[ offload-shared ]
		[ mac ]
		[ mac-shared ]
		[ phy ]
		[ phy-shared ]
		[ ram ]
		[ ram-shared ]
		[ ap ]
		[ ap-shared ]
		[ dedicated ]
		[ all ]
        ethtool --show-fec DEVNAME	Show FEC settings
        ethtool --set-fec DEVNAME	Set FEC settings
		[ encoding auto|off|rs|baser ]
        ethtool -h|--help 		Show this help
        ethtool --version 		Show version number

```
