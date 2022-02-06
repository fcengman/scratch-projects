function Post(title, body, author){
    this.title = title;
    this.body = body;
    this.author = author;
    this.views = 0;
    this.comment = [];
    this.isLive = false; 
}

function Comment(author, body){
    this.body = body;
    this.author = author;
}



const numbers = [
    {id: 1, name: 'a'}, {id: 2, name: 'b'},
];

console.log(numbers.find(element=>element.id === 1));