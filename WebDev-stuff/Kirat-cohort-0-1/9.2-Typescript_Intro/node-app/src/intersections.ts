type hello = {
  name: string;
  age: number;
};

interface hello2 {
  name: string;
  gender: number;
}

type helloLead2 = hello | hello2;

type helloLead = hello & hello2;
// the above equals to the below
type helloLead = {
  name: string;
  age: number;
  gender: number;
};
