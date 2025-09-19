using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class MakeSoundTests
    {
        [Test]
        [Category("MakeSound")]
        public void Cat_MakeSound_ShouldPrintMeow()
        {
            Cat cat = new Cat("Whiskers");

            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                cat.MakeSound();
                Assert.AreEqual("Meow!\r\n", sw.ToString());
            }
        }
		
		[Test]
        [Category("MakeSound")]
        public void Dog_MakeSound_ShouldPrintWoof()
        {
            Dog dog = new Dog("Rex");

            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                dog.MakeSound();
                Assert.AreEqual("Woof!\r\n", sw.ToString());
            }
        }
    }
    
}
