// all in one code that is all classes 
abstract class Element {
    abstract void print();
}
class Point extends Element{
    private double _x;
    private double _y;

    public void print(){
        System.out.println("("+this._x+","+this._y+")");
    }
    public Point(){
        System.out.println("Default constructor.\n");
        _x=0;
        _y=0;
    }

    public Point(double x,double y) {
        System.out.println("Parameterised constructor.\n");
        _x = x;
        _y = y;
    }
    public double distFrom(Point p){
        double dist_x=p._x-this._x;
        double dist_y=p._y-this._y;
        return Math.sqrt(dist_x*dist_x+dist_y*dist_y);
    }
    public Point midPoint(Point p){
        double mid_x=(this._x+p._x)/2.0;
        double mid_y=(this._y+p._y)/2.0;
        return new Point(mid_x,mid_y);
    }
    double get_x(){
        return this._x;
    }
    double get_y(){
        return this._y;
    }

}
public class oops {

    public static void main(String args[]){
        

        System.out.println ("hello world");
        Point p1=new Point(12.3,14.5);
        p1.print();
        Point p2=new Point(11.3,11.5);
        p2.print();
        Point p3=new Point();
        p3=p1.midPoint(p2);
        p3.print();

        // question 3
        Point [] point_cloud=new Point[10000];
        for(int i=0;i<10000;i++)
        {
            double _p_x=(Math.floor(Math.random()*100));
            double _p_y=(Math.floor(Math.random()*100));
            point_cloud[i]=new Point(_p_x,_p_y);
        }
        // for illustration
        for(int i=0;i<5;i++)
        {
            point_cloud[i].print();
        }
        double  centroid_x=0;
        double centroid_y=0;
        for(int i=0;i<10000;i++)
        {
            centroid_x+=(point_cloud[i].get_x())/10000;
            centroid_y+=(point_cloud[i].get_y())/10000;
        }
        System.out.println("Printing Centroid");
        Point centroid_p=new Point(centroid_x,centroid_y);
        centroid_p.print();
        // instance of
        Element ele=new Point();
        ele.print();
        System.out.println("Checking if ele is Element type:");
        System.out.println(ele instanceof Element);
        System.out.println("Checking if ele is Point type:");
        System.out.println(ele instanceof Point);

        //ele casting into point type
         Point pt=(Point) ele;
        double d=pt.distFrom(p1);
        System.out.println(d);

    }     
}  

             

    

    
