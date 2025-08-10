// let temp = parseFloat(prompt("Enter Celsius Temperature"))
// let fahrenheit = ((9 / 5) * temp) + 32;
// document.write(fahrenheit)

// let num = parseInt(prompt("Enter any number"))
// if(num < 0) document.write("Negative")
// else if(num > 0) document.write("Positive")
// else document.write("Zero")

// let char = prompt("Enter any character")
// if(char >= 'a' && char <= 'z') document.write("Lowercase")
// else document.write("Uppercase") 

// let c = prompt("Enter any character")
// // convert to lowercase
// switch(c){
//     case 'a':
//     case 'A':
//     case 'e':
//     case 'E':
//     case 'i':
//     case 'I':
//     case 'o':
//     case 'O':
//     case 'u':
//     case 'U':
//         document.write("Vowel")
//         break;
//     default:
//         document.write("Consonant")
// }

let sum = 0;
for(let i = 0; i <= 100; i++){
    if(i % 2 == 0) {
        sum += i;
    }
}
document.write(sum)
document.write("<br>")
sum = 0;
for(let i = 2; i <= 100; i += 2){
    sum += i;
}
document.write(sum)