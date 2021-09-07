class phone{
    String model;
    int value;

    void print(){
        System.out.println(value+"만원 짜리"+model+" 스마트폰");
    }
}
public class phonedemo {
    public static void main(String[] args){
        phone myPhone = new phone();
        myPhone.model = "갤럭시 s8";
        myPhone.value = 100;
        myPhone.print();
        phone yourPhone = new phone();
        yourPhone.model = "g6";
        yourPhone.value = 85;
        yourPhone.print();
    }
}
