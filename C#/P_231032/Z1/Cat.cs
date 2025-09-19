using System;
using System.Collections.Generic;
using System.Text;

namespace Z1
{
    public class Cat : Animal, IMovable
    {
        public Cat(string name) : base(name){}
        public void Move(){
            throw new NotImplementedException();
        }
    }
}
