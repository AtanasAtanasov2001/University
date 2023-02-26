package geometry;

import javafx.scene.Group;
import javafx.scene.paint.Color;

public class Line {
    private Point sPoint;// starting point
    private Point ePoint;// ending point

    public Line(Point sPoint, Point ePoint) {
        setsPoint(sPoint);
        setePoint(ePoint);
    }

    public Line() {
        this(new Point(), new Point(new double[]{5,10}));
    }

    public Line(Line l){
        this(l.sPoint,l.ePoint);
    }

    public Point getsPoint() {
        return new Point(sPoint);
    }

    public void setsPoint(Point sPoint) {
        if(sPoint != null) {
            this.sPoint = new Point(sPoint);
        } else {
            this.sPoint = new Point();
        }
    }

    public Point getePoint() {
        return new Point(ePoint);
    }

    public void setePoint(Point ePoint) {
        if(ePoint != null) {
            this.ePoint = new Point(ePoint);
        } else {
            this.ePoint = new Point();
        }
    }

    public void draw(Group pane){
        javafx.scene.shape.Line line = new
                javafx.scene.shape.Line(
                sPoint.getCoords()[0],sPoint.getCoords()[1],
                ePoint.getCoords()[0],ePoint.getCoords()[1]);
        line.setStroke(Color.RED);
        line.setStrokeWidth(3);
        pane.getChildren().add(line);
    }

    @Override
    public String toString() {
        return String.format("Starting point: %s, Ending point: %s",
                sPoint.toString(), ePoint.toString());
    }
}
