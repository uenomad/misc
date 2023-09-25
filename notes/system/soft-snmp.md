## SNMP

### Overview

Simple Network Management Protocol. An internet protocol built upon UDP for collecting information about devices in networks. One or more computers called managers manages a group of hosts. Each managed host executes a daemon called Agent, which reports information to the manager. The manager runs the Network Management Station (NMS) daemon. The device comunication can be unidirectional (Read-Only) or bidirectional (Read-Write). And each device belongs to a one or mulitple networks called Communities.

An Agent exposes variables organized in hierarchies, described in a Management Information Base (MIB) format object which defines the variable IDs (OID) within the hierarchies. 

The Manager sends messages through port 161 and receive responses or alerts from port 162. These messages are called PDUs (Protocol Data Units):
1) GetRequest to retrieve a value of a variable.
2) SetRequest to change a value of a variable.
3) GetNextRequest to discover available variables and their values. You can retrieve the entire MIB by using this PDU with OID 0. 
4) GetBulkRequest for multiple iterations of GetNextRequest.

### Documentation

1) [Net-SNMP tutorials](http://www.net-snmp.org/wiki/index.php/Tutorials).  

### Using commands

- Use commands like `snmpwalk` to retrieve the subtree of values, it works by using GetNextRequest under the hood.
- GetRequest command through `snmpget`.
- I

### Using the library

- [Read simple application tutorial](http://www.net-snmp.org/wiki/index.php/TUT:Simple_Application).
- Required to initialize session:
  - SNMP version (1 to 3).
  - Community.
  - Security name.
  - Encryption (MD5, SHA, AES...)
- Required to get variable:
  - OID.