class dogdemo {
    public static void main(String[] args) {
        Dog d1 = new Dog();
        d1.setName("啸天犬");
        d1.setAge(999);
        d1.setKind("猎狗");
        d1.setHost("二郎神");
        d1.setPrice(10000);
        System.out.println(d1.getName());
        System.out.println(d1.getAge());
        System.out.println(d1.getKind());
        System.out.println(d1.getHost());
        System.out.println(d1.getPrice());
        Dog d2 = new Dog();
        d2.setName("罗小黑");
        d2.setAge(5);
        d2.setKind("神奇犬");
        d2.setHost("大自然");
        d2.setPrice(999.99);
        System.out.println(d2.getName());
        System.out.println(d2.getAge());
        System.out.println(d2.getKind());
        System.out.println(d2.getHost());
        System.out.println(d2.getPrice());

        d1.run();
        d1.eat(5);
        d1.sleep(8.8);
        d1.plau(d1.getHost());
    }
}
class Dog{
    private String name;
    private int age;
    private String kind;
    private String host;
    private double price;
    public void run(){
        System.out.println("小狗Dog跑的老快了~");
    }
    public void eat(int n){
        System.out.println("小狗今晚要吃"+n+"根骨头");
    }
    public void sleep(double num){
        System.out.println("小狗今晚睡了"+num+"个小时");
    }
    public String plau(String host){
        System.out.println("小狗与主人"+host+"玩的很开心");
        bark();
        return "飞盘";
        //bark():
    }
    public void bark(){
        System.out.println("小狗喜欢汪汪叫");
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public int getAge(){
        return age;
    }
    public void setAge(int age){
        this.age = age;
    }
    public String getKind(){
        return kind;
    }
    public void setKind(String kind){
        this.kind = kind;
    }
    public String getHost(){
        return host;
    }
    public void setHost(String host){
        this.host = host;
    }
    public double getPrice(){
        return price;
    }
    public void setPrice(double price){
        this.price = price;
    }


}