// let a = "8"
// let b = 9
// var ab = "saksham"
// // console.log(typeof(a+b))

// const c = 9;

// const obj ={
//     word:"meaning",
//     "Play":"khelna",
//     "DAnce":"nachna"
// }
// console.log(obj)
// console.log(2**5);

// function hello(){
//     let a = "saksham";
//     ab = 98;
//     c = 23;
//     console.log(c)
//     // console.log(a);
// }
//     // console.log(ab)
// console.log(c)

// hello();
// // console.log(ab)
// // console.log(a)

// var a;
// let b;
// console.log(a);
// console.log(b);

// function sum( a,  b){
//     return a+b;
// }
// function greet(name) {
//   return "Hello, " + name; // returns a String
// }

// const obj = {
//     a:20,
//     b:45,
//     c:32,
// }

// // for(let i=0; i<obj)

// for(let names in obj){
//     console.log(names , ":", obj[names]);
// }
// // console.log(greet(5))
// let ans = sum(2,3);
// console.log(ans);

// let str = "SAksham manav"
// str[0] = 'A'
// let str2 = str.replace("manav", "pandey")

// console.log(str)
// console.log(str2)

// let arr = [1,2,3];
// arr.splice(1,1,23,34)
// console.log(arr)

// let arr = ["a", "b", "c"];

// arr.forEach((val, i) => {
//   console.log(i, val);
// });

// console.warn("It is not good")
// console.log(arr.toString())
// console.log(arr.pop())
// arr = arr.join("+")

// console.log(typeof(arr))


// function sum(a,b){
//   console.log(a+b);
// }
// function mult(a,b){
//   console.log(a*b);
// }
// function calculator(a, b, sum){
//   sum(a,b);
// }

// calculator(1,2,sum);
// calculator(2,3,mult);

let promise = new Promise((res, rej)=>{
  console.log("promise");
  res("Success")
})