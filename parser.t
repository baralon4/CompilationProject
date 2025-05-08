def foo(par1 int:i; par2 int:j): returns int
    var
        type int: x;
        type int: y;
    begin
        var
            type int: y;
            type int: X;
        begin
            x = 1;
            y = 2;
            begin
                x = 2;
            end
            y = 3;
        end
        return 1;
    end

def goo(): returns int
    begin
        begin
            begin 
            end 
        end
        return 0;
    end
