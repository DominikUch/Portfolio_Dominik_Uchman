
using NUnit.Framework;
using System.Collections.Generic;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class WplataEventTests
    {
        [Test]
        [Category("WplataEvent")]
        public void Wplata_WykonujeOperacjeFinansowaEvent_ZPoprawnymiArgumentami()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal kwota = 1000;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta� wywo�any z prawid�owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "Wp�ata �rodk�w");
            };

            rachunek.Wp�a�(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta� wywo�any.");
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_WykonujeOperacjeFinansowaEvent_ZUjemn�Kwot�()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal kwota = -1000;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta� wywo�any z prawid�owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "B��d: Pr�ba wp�aty �rodk�w mniejszych b�d� r�wnych zero.");
            };

            rachunek.Wp�a�(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta� wywo�any.");
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_WykonujeOperacjeFinansowaEvent_ZPustaListaInvoke()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal kwota = -1000;
            bool eventCalled = false;

            rachunek.Wp�a�(kwota);

            // Assert
            Assert.IsFalse(eventCalled);
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_GlobalnyRejestrOperacji_WykonujeOperacjeFinansowaEvent_ZPoprawnymiArgumentami()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            List<OperacjaFinansowaEventArgs> globalnyRejestrOperacji = new List<OperacjaFinansowaEventArgs>();
            rachunek.OnOperacjaFinansowa += (sender, args) =>
            {
                globalnyRejestrOperacji.Add(args);
            };

            // Act
            rachunek.Wp�a�(100);
            rachunek.Wp�a�(50);

            // Assert
            Assert.AreEqual(2, globalnyRejestrOperacji.Count);
            Assert.AreEqual(100, globalnyRejestrOperacji[0].Kwota);
            Assert.AreEqual("Wp�ata �rodk�w", globalnyRejestrOperacji[0].Opis);
            Assert.AreEqual(50, globalnyRejestrOperacji[1].Kwota);
            Assert.AreEqual("Wp�ata �rodk�w", globalnyRejestrOperacji[1].Opis);
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_GlobalnyRejestrOperacji_WykonujeOperacjeFinansowaEvent_Clone()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            object senderTest = null;

            List<OperacjaFinansowaEventArgs> globalnyRejestrOperacji = new List<OperacjaFinansowaEventArgs>();
            rachunek.OnOperacjaFinansowa += (sender, args) =>
            {
                globalnyRejestrOperacji.Add(args);
                senderTest = sender;
            };

            // Act
            rachunek.Wp�a�(100);

            // Assert
            Assert.IsFalse(senderTest == rachunek);
        }
    }
}
