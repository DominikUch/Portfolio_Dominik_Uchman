using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class MoveTests
    {
        [Test]
        [Category("Move")]
        public void Dog_Move_ShouldPrintDogIsRunning()
        {
            Dog dog = new Dog("Rex");

            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                dog.Move();
                Assert.AreEqual("Dog is running!\r\n", sw.ToString());
            }
        }
    }
    
}
