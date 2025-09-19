
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
                // Sprawdzamy czy event zosta³ wywo³any z prawid³owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "Wp³ata œrodków");
            };

            rachunek.Wp³aæ(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta³ wywo³any.");
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_WykonujeOperacjeFinansowaEvent_ZUjemn¹Kwot¹()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal kwota = -1000;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta³ wywo³any z prawid³owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "B³¹d: Próba wp³aty œrodków mniejszych b¹dŸ równych zero.");
            };

            rachunek.Wp³aæ(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta³ wywo³any.");
        }

        [Test]
        [Category("WplataEvent")]
        public void Wplata_WykonujeOperacjeFinansowaEvent_ZPustaListaInvoke()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal kwota = -1000;
            bool eventCalled = false;

            rachunek.Wp³aæ(kwota);

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
            rachunek.Wp³aæ(100);
            rachunek.Wp³aæ(50);

            // Assert
            Assert.AreEqual(2, globalnyRejestrOperacji.Count);
            Assert.AreEqual(100, globalnyRejestrOperacji[0].Kwota);
            Assert.AreEqual("Wp³ata œrodków", globalnyRejestrOperacji[0].Opis);
            Assert.AreEqual(50, globalnyRejestrOperacji[1].Kwota);
            Assert.AreEqual("Wp³ata œrodków", globalnyRejestrOperacji[1].Opis);
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
            rachunek.Wp³aæ(100);

            // Assert
            Assert.IsFalse(senderTest == rachunek);
        }
    }
}
