# CPP_2019_CA2_TS_AR
Pair Project Project For C++ Module

## Functional Requirements:
For this assignment, each group is required to develop a Point of Sale (POS) and Stock Control system entitled MyPOS, for a small clothing store. The store is a stand-alone store and therefore the system is not required to provide any network connectivity or features.


Each item of stock in the system must contain the following information:
* ID          int     (Auto Generated)
* Title       String  Length >= 4 characters
* Colour      String  Length >= 3 characters
* Size        String  Any of the following values: XS, S, M, L, XL, XXL,XXXL 
* Quantity    Int     Any valid integer >=15
* Cost        Float   Any valid float >=0.0149.99

You must also create a Sale item with the following properties:
* ID                    int(Auto Generated)
* Sales Assistant       StringLength >=4 characters
* ItemsList<StockItem*> More than one item
