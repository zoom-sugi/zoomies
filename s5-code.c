void show_error(void) {

 // AUTHENTICATION ERROR

exit(-1);

}

int main(int argc, char **argv) {
char error_on_auth='1';
char user[128];
char pass[128];
char *ch_ptr_begin;
char *ch_ptr_end;

 /**********************************/
 /* Get Username from Query String */
 /**********************************/
 ch_ptr_begin=(char *)strstr(****QUERY_STRING****,"login=");
 if (ch_ptr_begin==NULL)
             show_error();
 ch_ptr_begin+=6;
 ch_ptr_end=(char *)strstr(ch_ptr_begin,"&");
 if (ch_ptr_end==NULL) 
             show_error();
 *(ch_ptr_end++)='\0';
 strcpy(user,ch_ptr_begin);


 /**********************************/
 /* Get Password from Query String */
 /**********************************/
 ch_ptr_begin=(char *)strstr(ch_ptr_end,"password=");
 if (ch_ptr_begin==NULL) 
             show_error();
 ch_ptr_begin+=9;
 ch_ptr_end=(char *)strstr(ch_ptr_begin,"&");
 if (ch_ptr_end!=NULL) *(ch_ptr_end++)='\0';
 strcpy(pass,ch_ptr_begin);


 if ((strcmp(user,GOOD_USER)==0) && (strcmp(pass,GOOD_PASS)==0)) error_on_auth='0';

 if (error_on_auth=='0') {
  
    // AUTHENTICATION OK!!


    } else {

    // AUTHENTICATION ERROR
    show_error();


    }

 // return(0); hehe could be evil ;PPPPP
 exit(0);

}

