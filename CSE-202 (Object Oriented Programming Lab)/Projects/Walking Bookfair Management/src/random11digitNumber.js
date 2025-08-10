// random 11 digit number generator starting with 018

const random11digitNumber = () => {
    const random = Math.floor(Math.random() * 1000000000);
    return `018${random}`;
}

for(let i = 0; i < 20; i++) {
    console.log(random11digitNumber());
}