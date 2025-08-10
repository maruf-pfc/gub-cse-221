// let r = document.getElementById("root")
// r.innerHTML = "Hello World!"

// document.write("<h2>Hello World!</h2>");
// console.log("Hello World!")

// window.alert("Close me!")

// function writeData(){
//     document.write(lyrics);
// }

let a = 33;
let b = 10;
let c = "Test";
let lineBreak = '<br>';

document.write('a + b = ');
let result = a + b;
document.write(result)
document.write(lineBreak);


document.write('a - b = ');
result = a - b;
document.write(result)
document.write(lineBreak);

document.write('a * b = ');
result = a * b;
document.write(result)
document.write(lineBreak);

document.write('a / b = ');
result = a / b;
document.write(result)
document.write(lineBreak);

document.write('a % b = ');
result = a % b;
document.write(result)
document.write(lineBreak);

document.write('a + b + c = ');
result = a + b + c;
document.write(result)
document.write(lineBreak);

document.write('++a = ');
a = ++a;
document.write(result)
document.write(lineBreak);

document.write('++b = ');
b = ++b;
document.write(result)
document.write(lineBreak);



let n1 = parseInt(prompt("Enter first number"));
let n2 = parseInt(prompt("Enter second number"));
let sum = n1 + n2;
document.write(`${n1} + ${n2} = ${sum}`);
document.write(lineBreak);