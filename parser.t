def foo(par1 int:i; par3 int:j; par2 int:k): returns int
   var
        type char*:x;
        type string y[10];
        type char:z;
    begin
        y = "foobar";
        x = &y[5]; #-> x points to 'r' <-#
        z = *x; #-> z is 'f' <-#
        y = "barfoo"; #-> z is still 'f', but x now points to 'o' <-#
    end



def _main_(): 
    begin
       return 0;
    end