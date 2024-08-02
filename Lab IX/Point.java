
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