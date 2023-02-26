function whatNumberItIs(number){
   
    let toReturn = number.length == 1 ? "0" + number : number;
    
    return toReturn;
}

function RGBtoHEX(r,g,b) {
    //r,g,b <- [0,255]
    //hex - 6 digits
    let toReturn = whatNumberItIs(r.toString(16)) + whatNumberItIs(g.toString(16)) + whatNumberItIs(b.toString(16));
    return toReturn;
    //should return hex
}
console.log(RGBtoHEX(0,191,255));