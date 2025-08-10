// task 1
let cTemp = parseFloat(prompt("Enter temp in celsius: "));
let fTemp = cTemp * (9 / 5) + 32;
document.write(`Given Celsius Temperature = ${cTemp}`)
document.write('<br>')
document.write(`Converted Fahrenheit Temperature = ${fTemp}`)
document.write('<br>')

// task 2
let n = parseInt(prompt("Enter any number"))
if(n == 0){
    document.write('Zero')
}else if(n > 0){
    document.write('Positive')
}else{
    document.write('Negative')
}
document.write('<br>')

let char = prompt("Enter any character: ")
if(char >= 'a' && char <= 'z'){
    document.write("Lowercase")
}else{
    document.write("Uppercase")
}
document.write('<br>')

// task 3
char.toLocaleLowerCase()
switch(char){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        document.write("Vowel");
        break;
    default:
        document.write("Consonant");
}
document.write('<br>')

// task 4
let sum = 0;
for(let i = 2; i <= 100; i += 2){
    sum += i;
}
document.write("Sum of 1 to 100 = " + sum);
document.write('<br>')