#include <stdio.h>
#include <openssl/bio.h>

int main()
{
    BIO* b = NULL;
    int len = 0;
    char* out = NULL;

    b = BIO_new(BIO_s_mem());//参数是一个函数
    /* char data[] = "Hello World";
     BIO *mem;
     mem = BIO_new_mem_buf(data, -1);//可以设置BIO为只读的
     */
    len = BIO_puts(b, "hello world\n");
    len = BIO_write(b, "openssl", 7);
    len = BIO_printf(b,"%s","zcp");
    len = BIO_ctrl_pending(b);
    out = (char*)OPENSSL_malloc(len);
    len = BIO_read(b, out, len);
    printf("%s", out);
    OPENSSL_free(out);
    BIO_free(b);
}

