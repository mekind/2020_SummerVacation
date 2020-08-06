
// 변수 이름은 숫자로 시작 x 
// keyword, reserved word는 변수 이름 x
var name ="dd dd";


// 상수 변수

const val=15; // 이게 상수

let res = false; // 이게 변수

//유효 범위  -> 블록스코프 
// var --> 함수 스코프

//hoisting  함수/ 변수를 아래에서 선언만 끌어올려서 사용
hello1();
function hello1(){
    console.log("hello1");
}

age=1;
console.log(age);

var age;

//자료형  (typeof 로 확인)
// 기본타입 boolean number string null undefined symbol 형변환 가능
// 객체 

console.log(typeof 1);

const a = 'Rr';
const b = `${a}   ddd`;

console.log(b);

// 조건문  false: 0, null, undefined, NaN
if (true){
    console.log('ddd');
}
else if(1) {

}
else{

}

//삼항 연산자 조건? 참 : 거짓 ;
//switch

/* 반복문  for( a; b; c){
    d
}
a -> d -> c -> b -> d -> c ....
*/


// while () {} 이것도 반복문  c++이랑 같네

// for of
for(const i of [1,2,3]){
    console.log(i);
}

// for in 이거는 이해 못했음 


// 함수를 만들어 보자

function hello11(){
    console.log('hello11');
}

console.log(hello11, typeof hello11);

function hello2(name){  
    console.log('hello2',name);
}

function hello3(name){
    return `hello3 ${name}`;
}

hello2('hihi');
console.log(hello3('hihi'));

/// 이렇게도 됨 호이스팅 때문에 오류 날 수 있음 
const hello4 = function(){
    console.log('hello4');
};
hello4();
console.log(hello4, typeof hello4);

// 생성자 함수로 만들 수 있음 (잘 안 쓰임) const sum = new Function('a', 'b', 'c', 'return a+b+c');

// arrow funciton 

const hello5 = ()=>{
    console.log('hello5');
};

hello5();

// 객체 함수 (arrow function으로는 불가능 )

function Person( name, age){
    this.name = name;
    this.age= age;
}

const p = new Person('kk', 23);

console.log(p, p.name, p.age);


//함수 안에 함수 

function plus(base){
    return function(num){
        return base+num;
    }
}

const plus5 = plus(5);
console.log(plus5(10));

// 함수를 인자로 사용

function hh(c){
    console.log('hello c');
    c();
}

hh(function(){
    console.log('콜백');
});


//객체 (생성자 함수)

function A(){
    this.a=1;
    this.b='1212';
    this.hihi=function(){
        console.log('fff');
    }
}
const aa = new A();
aa.hihi();
console.log(aa);

// 객체 (new Object()) 권장하지 않음

{
    const tt= new Object();
    console.log(tt, typeof tt);

}

// prototype(이부분은 더 공부해야될 듯) toString constructor

// 상속  aaa.prototype=bbb.prototype; (잘 모르겟음 )

// 객체 리터럴
{
    const tmp = {
        name : 'djdj',
        rrr(){
            console.log('hehehe');
        },
    };
    console.log(tmp, typeof tmp);
    tmp.rrr();
}

// 표준 내장 객체 mdn
{
    const tmp = new Array('red', 'black', ' white');
    console.log(tmp, typeof tmp);
    console.log(tmp.slice(0,1));
}


//클래스 es6부터 추가

//class 

//선언적 방식

{
    class tmp {
        constructor(name, age){
            this.name=name? name: 'no name';
            this.age=age ? age : 5;
            console.log(`hi ${name}`);
        }
    }
    console.log(new tmp('kds',1));
    console.log(new tmp());
}

//get set

{
    class tmp{
        _name = 'no name';
        get name(){
            return this._name;
        }
        set name(val){
            this._name=val+'!!';
        }
    }

    const pp=new tmp();
    console.log(pp);
    pp.name='kds';
    console.log(pp);
}

//static 함수 변수 java랑 똑같음 

//extends 상속 (자바랑 똑같음) (super)
{
    class tmp{
        name='no name';
        age =0;
    }
    class ttmp extends tmp{}
    console.log(new ttmp());
}

// override 오버라이딩 

console.log('promise');
//promise 프로미스 (이 부분은 다시 공부해야됨 )

{
    console.log(Promise);


    const tmp = new Promise((resolve, reject)=>{
        //  pending ...
        setTimeout(()=>{
            resolve();// fullfiled 이행
        },1000);
        //reject();// rejected
    });

    tmp.then(/* callback */()=>{
        console.log('1000ms 후에 fullfilled 됩니다.');
    });
}

{
    function pp(){ // pending을 늦추기 위해 이렇게 만드는 것이 옳은 방법 
        return new Promise((resolve, reject)=>{
            //  pending ...
            setTimeout(()=>{
                //resolve();// fullfiled 이행
                reject();
            },1000);
            //reject();// rejected
        });
    }
    
    pp()
        .then(() => {
            console.log('1000ms 후에 fullfilled 됩니다.');
        })
        .catch(() => {
            console.log('1000ms 후에 rejectd 됩니다.');
        })
        .finally(()=>{
            console.log('the end');
        });

}

//async function 