package main;
import "fmt";

// Let's try an import list!

import(
	"math";
	"net";
)
var a int;
func main() {
	var b string;
	fmt.PrintLn();
	a = 20 * 10 + b;
	a = 20 * (10 + b);
}
/*That work*/