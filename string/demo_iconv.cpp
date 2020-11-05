#include <string.h>
#include <iconv.h>
#include <iostream>

using namespace std;

int code_convert(char *from_charset, char *to_charset, char *inbuf,int inlen,
				char *outbuf,int outlen)
{
    iconv_t cd;

    char **pin = &inbuf;
    char **pout = &outbuf;

    cd = iconv_open(to_charset,from_charset);
    if (cd == 0)
    {
        return -1;
    }
    memset(outbuf,0,outlen);
    std::size_t inlen_t = (std::size_t)inlen;
    std::size_t outlen_t = (std::size_t)outlen;
    if (iconv(cd,pin,&inlen_t,pout,&outlen_t) == -1)
    {
        return -1;
    }

    iconv_close(cd);

    return 0;
}


int gb2312ToUtf8(char *inbuf,int inlen,char *outbuf,int outlen)
{
    return code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
}

string gb2312ToUtf8(char *inbuf)
{
    if (NULL == inbuf)
    {
        return string("");
    }

    char errmsg[256] = { 0 };
    gb2312ToUtf8(inbuf,strlen(inbuf),errmsg,256);

    return string(errmsg);
}



int main(int argc, char *argv[])
{
    char *str = "中文";
    string s = gb2312ToUtf8(str);
    cout << "s: " << s << endl;

    return 0;
}
