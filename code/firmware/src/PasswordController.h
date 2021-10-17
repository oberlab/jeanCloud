#ifndef PasswordController_h
#define PasswordController_h

class PasswordController
{
public:
    PasswordController(String _path);
    void writeCredentials(String _ssid, String _password);
    String getSSID();
    String getPassword();
    bool isExisting();

private:
    String path;
    String ssid;
    String password;
    bool exists;
};

#endif
