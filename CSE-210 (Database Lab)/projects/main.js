const fs = require("fs");

// CREATE TABLE Addresses (
//     address_id NUMBER PRIMARY KEY,
//     address_details VARCHAR2(255)
// );
function random3characters() {
  const characters = "abcdefghijklmnopqrstuvwxyz";
  let result = "";
  for (let i = 0; i < 3; i++) {
    result += characters.charAt(Math.floor(Math.random() * characters.length));
  }
  return result;
}
function random10characters() {
  const characters = "abcdefghijklmnopqrstuvwxyz";
  let result = "";
  for (let i = 0; i < 10; i++) {
    result += characters.charAt(Math.floor(Math.random() * characters.length));
  }
  return result;
}
function generate4To7Characters() {
  const characters = "abcdefghijklmnopqrstuvwxyz";
  let result = "";
  for (let i = 0; i < Math.floor(Math.random() * 4) + 4; i++) {
    result += characters.charAt(Math.floor(Math.random() * characters.length));
  }
  result = result[0].toUpperCase() + result.slice(1);
  return result;
}
function generateRandomFullName() {
  let firstName = generate4To7Characters();
  let lastName = generate4To7Characters();
  return `${firstName} ${lastName}`;
}

const firstNames = [
  "Alice",
  "Bob",
  "Charlie",
  "Diana",
  "Eva",
  "Frank",
  "Grace",
  "Henry",
  "Ivy",
  "Jack",
];

const lastNames = [
  "Adams",
  "Brown",
  "Clark",
  "Davis",
  "Evans",
  "Garcia",
  "Hill",
  "Jones",
  "King",
  "Lopez",
];
function generateRandomName() {
  const randomFirstName =
    firstNames[Math.floor(Math.random() * firstNames.length)];
  const randomLastName =
    lastNames[Math.floor(Math.random() * lastNames.length)];
  const randomFullName = `${randomFirstName} ${randomLastName}`;

  return randomFullName;
}

function generateRandomAddress() {
  const cities = [
    "New York",
    "Los Angeles",
    "Chicago",
    "San Francisco",
    "Boston",
    "Seattle",
    "Miami",
    "Dallas",
    "Philadelphia",
    "Denver",
    "Bangladesh",
    "India",
    "Pakistan",
    "Nepal",
    "Bhutan",
    "Sri Lanka",
    "Afghanistan",
    "Myanmar",
    "Thailand",
    "Vietnam",
    "Cambodia",
    "Laos",
    "Malaysia",
    "Indonesia",
    "Philippines",
    "Singapore",
    "Brunei",
    "Australia",
    "New Zealand",
    "Fiji",
    "Samoa",
    "Tonga",
    "Solomon Islands",
    "Papua New Guinea",
    "Vanuatu",
    "Kiribati",
    "Tuvalu",
    "Nauru",
    "Marshall Islands",
    "Palau",
    "Micronesia",
    "Japan",
    "South Korea",
    "North Korea",
    "China",
    "Mongolia",
    "Taiwan",
    "Hong Kong",
    "Macau",
    "Russia",
    "Kazakhstan",
    "Uzbekistan",
    "Turkmenistan",
    "Kyrgyzstan",
    "Tajikistan",
    "Iran",
    "Iraq",
    "Syria",
    "Lebanon",
    "Jordan",
  ];
  const randomCity = cities[Math.floor(Math.random() * cities.length)];
  const randomStreetName = random3characters();
  const randomStreetNumber = Math.floor(Math.random() * 1000) + 1;
  const randomAddress = `${randomStreetNumber}-${randomStreetName} Road, ${randomCity}`;

  return randomAddress;
}

function Addresses() {
  let data = "";
  // write the function call output to a file
  for (let i = 1; i <= 10000; i++) {
    data += `insert into Addresses3 (address_id, address_details) VALUES (${i}, '${generateRandomAddress()}');\n`;

    // write the function call output to a file
    fs.writeFileSync("Addresses.sql", data);
  }
}

Addresses();

// CREATE TABLE Schools (
//     school_id NUMBER PRIMARY KEY,
//     address_id NUMBER,
//     school_name VARCHAR2(255),
//     school_principal VARCHAR2(255),
//     other_school_details VARCHAR2(255),
//     FOREIGN KEY (address_id) REFERENCES Addresses(address_id)
// );

function generateRandomSchools() {
  let randomSchoolName1 = random10characters();
  randomSchoolName1[0] = randomSchoolName1[0].toUpperCase();
  let randomPrincipal = generateRandomFullName();
  let randomSchoolName2 = random10characters();
  randomSchoolName2[0] = randomSchoolName2[0].toUpperCase();

  return `'${randomSchoolName1} High School', '${randomPrincipal}', '${randomSchoolName2} High School'`;
}

function Schools() {
  let data = "";
  // write the function call output to a file
  for (let i = 1; i <= 10000; i++) {
    let temp = generateRandomSchools();
    data += `insert into Schools3 (school_id, address_id, school_name, school_principal, other_school_details) VALUES (${i}, ${i}, ${temp});\n`;

    // write the function call output to a file
    fs.writeFileSync("Schools.sql", data);
  }
}

Schools();

// CREATE TABLE Parents (
//     parent_id NUMBER PRIMARY KEY,
//     gender CHAR(1),
//     first_name VARCHAR2(255),
//     middle_name VARCHAR2(255),
//     last_name VARCHAR2(255),
//     other_parent_details VARCHAR2(255)
// );

function generateRandomParents() {
  let randomGender = Math.random() < 0.5 ? "M" : "F";
  let randomFirstName = generate4To7Characters();
  let randomLastName = generate4To7Characters();
  let randomParentDetails = 'N/A';

  return `'${randomGender}', '${randomFirstName}', '${randomLastName}', '${randomParentDetails}'`;
}

function Parents() {
  let data = "";
  // write the function call output to a file
  for (let i = 1; i <= 10000; i++) {
    let temp = generateRandomParents();
    data += `INSERT INTO Parents3 (parent_id, gender, first_name, last_name, other_parent_details) VALUES (${i}, ${temp});\n`;

    fs.writeFileSync("Parents.sql", data);
  }
}

Parents();
