public class Main {

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

             

    

    
