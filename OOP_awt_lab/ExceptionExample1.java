import java.util.Random;

public class ExceptionExample1 {
    public void module1(){
        int a, b=0, c=0;
        Random r=new Random();
        try{
            b=r.nextInt(); c=r.nextInt();
            a=b*c;
            a/=b;
            a/=c;
        }
        catch (ArithmeticException e){
            System.out.println("Exception is:"+e.toString());
            a=0;
        }
        System.out.println(a);
    }
    public void module2(){
        int a, b=0, c=0;
        Random r=new Random();
        try{
            a=b*c;
            a/=b;
            a/=c;
        }
        catch (Exception e){
            System.out.println("Generic:"+e.toString());
            a=0;
        }
        /*
        catch (ArithmeticException e){
            System.out.println("Exception is:"+e.toString());
            a=0;
        }
        */
        System.out.println(a);
    }
    public void module3(int i){
        try{

            if(i==0){
                int a=2/0;
            }

            try{
                if(i==1) {
                    int[] b = {1};
                    b[1] = 3;
                }
                else{
                    int c=3/0;
                }
            }
            catch (ArrayIndexOutOfBoundsException e){
                System.out.println(e);
            }
        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
    }
    public void module4Helper(int i){
        try{
            if(i==1) {
                int[] b = {1};
                b[1] = 3;
            }
            else{
                int c=3/0;
            }
        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
    }
    public void module4(int i){
        try{

            if(i==0){
                int a=2/0;
            }
            module4Helper(i);
        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
    }
    public void module5Helper(){
        try{
            throw new ArrayIndexOutOfBoundsException("Demo");
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("First: "+e);
            throw e;
        }
    }
    public void module5(){
        try{
            module5Helper();
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Second: "+e);
        }
    }
    public void module6Helper(int i) throws ArithmeticException, ArrayIndexOutOfBoundsException{
        if(i==0)throw new ArithmeticException("Demo1");
        else if(i==1) throw new ArrayIndexOutOfBoundsException("Demo2");
        else throw new NullPointerException("Demo3");
    }
    public void module6(int i){
        try{
            module6Helper(i);
        }
        catch (ArithmeticException e){
            System.out.println(e);
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }
        catch (Exception e){
            System.out.println(e);
        }
        finally {
            System.out.println("Finally Block!");
        }
    }
    public static void main(String[] args){
        ExceptionExample1 e=new ExceptionExample1();
        e.module1();
        e.module2();
        e.module3(0);
        e.module3(1);
        e.module4(0);
        e.module4(1);
        e.module5();
        e.module6(0);
        e.module6(1);
        e.module6(2);
    }
}
