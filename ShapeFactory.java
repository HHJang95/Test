package com.example.myapplication;

public class ShapeFactory {
    public Shape getShape(String shapetype){
        if(shapetype.equalsIgnoreCase("CIRCLE")){
            return new Circle();
        }
        else if(shapetype.equalsIgnoreCase("Rectangle")){
            return new Circle();
        }
        else return null;
    }
}
