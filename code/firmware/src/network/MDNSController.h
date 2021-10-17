#ifndef mdnsController_h
#define mdnsController_h

class MDNSController
{
public:
    MDNSController(char *_hostname, char *_instanceName);
    bool setup();

private:
    char *hostname;
    char *instanceName;
};
#endif
