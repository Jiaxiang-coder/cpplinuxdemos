#include <unistd.h>
#include <pwd.h>
#include <cstdlib>
#include <stdio.h>

int main()
{
	const char* pstrUN = getenv("username");
	printf("user name is \"%s\"\n", getenv("username"));
	uid_t userid;
	struct passwd* pwd;
    	userid=getuid();
    	pwd=getpwuid(userid);
	//return pwd->pw_name;
	printf("user name from getuid is \"%s\"\n", pwd->pw_name);
	return 0;
}
