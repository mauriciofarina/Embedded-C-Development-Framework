# Layer 3 (Applications)

TODO: Document


<!-- It is the last framework layer and is responsible for the deployment of every system flow. Application can be designed as RTOS threads or bare-metal state machines. In ether cases, applications can only include modules from layer 2.
A common problem faced by novice developers is the unexpected behavior caused by not take into consideration the implications running code outside RTOS context. For that reason, every CORE should contain a System application (even for bare-metal projects). It is a special application that should be seen as the ”main function” for the project. All systems initialization and starting of other tasks should be done inside of it. This NFC ensures that every developers execute all CORE code in RTOS environment. Finally, starting the System task should be done by PROJECT and is, strictly, the only framework exception. -->