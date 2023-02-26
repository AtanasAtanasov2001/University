package package3a;

public class OuterClassA {
    public OuterClassA() {

    }

    @Override
    public String toString() {
        System.out.println("OuterClassA");
        return "OuterClassA";
    }



    public InnerClassA getInnerClassA(String s) {
        return new InnerClassA(s);
    }

    static class InnerClassA {
        private String myName;

        public InnerClassA(String myName) {}

        public void setMyName(String myName) {
            if(myName == null) {
                myName = "Inner";
            }
            else {
                this.myName = myName;
            }
        }

        public String getMyName() {
            return myName;
        }

        @Override
        public String toString() {
            System.out.println("InnerClassA" + myName);
            return "InnerClassA";
        }
    }
}
