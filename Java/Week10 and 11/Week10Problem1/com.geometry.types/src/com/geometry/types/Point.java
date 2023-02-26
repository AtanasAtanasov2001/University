package com.geometry.types;

public class Point implements Comparable{
    private int x;
    private int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point(){
        this(0,0);
    }

    public Point(Point p) {
        this(p.x,p.y);
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    @Override
    public int compareTo(Object o) {
        if(o == null) return 1;
        if(!(o instanceof Point)) return 1;
        Point p = (Point) o;
        if((x - p.x) * (y- p.y) > 0) return x - p.x;
        if(x - p.x == 0) return y - p.y;
        return x -  p.x;
    }

    @Override
    public String toString() {
        return String.format("(%d; %d)",x,y);
    }
}
