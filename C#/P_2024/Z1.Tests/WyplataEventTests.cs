
using NUnit.Framework;
using System.Collections.Generic;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class WyplataEventTests
    {
        [Test]
        [Category("WyplataEvent")]
        public void Wyplata_WykonujeOperacjeFinansowaEvent_ZPoprawnymiArgumentami()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunek.Wp�a�(1000);
            decimal kwota = 100;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta� wywo�any z prawid�owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "Wyp�ata �rodk�w");
            };


            rachunek.Wyp�a�(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta� wywo�any.");
        }

        [Test]
        [Category("WyplataEvent")]
        public void Wyplata_WykonujeOperacjeFinansowaEvent_ZaDuzaKwotaWyplaty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunek.Wp�a�(1000);
            decimal kwota = 10000;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta� wywo�any z prawid�owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "B��d: Brak wystarczaj�cych �rodk�w na rachunku.");
            };


            rachunek.Wyp�a�(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta� wywo�any.");
        }

        [Test]
        [Category("WyplataEvent")]
        public void Wyplata_WykonujeOperacjeFinansowaEvent_UjemnaKwotaWyplaty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            rachunek.Wp�a�(1000);
            decimal kwota = -1;
            bool eventCalled = false;

            // Act
            rachunek.OnOperacjaFinansowa += (sender, e) =>
            {
                eventCalled = true;
                // Sprawdzamy czy event zosta� wywo�any z prawid�owymi parametrami
                Assert.AreEqual(sender, rachunek);
                Assert.AreEqual(e.Kwota, kwota);
                Assert.AreEqual(e.Opis, "B��d: Brak wystarczaj�cych �rodk�w na rachunku.");
            };


            rachunek.Wyp�a�(kwota);

            // Assert
            Assert.IsTrue(eventCalled, "OperacjaFinansowa event nie zosta� wywo�any.");
        }

        [Test]
        [Category("WyplataEvent")]
        public void Wyplata_GlobalnyRejestrOperacji_WykonujeOperacjeFinansowaEvent_ZPoprawnymiArgumentami()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            List<OperacjaFinansowaEventArgs> globalnyRejestrOperacji = new List<OperacjaFinansowaEventArgs>();
            rachunek.OnOperacjaFinansowa += (sender, args) =>
            {
                globalnyRejestrOperacji.Add(args);
            };

            // Act
            rachunek.Wp�a�(1000);
            rachunek.Wyp�a�(100);
            rachunek.Wyp�a�(50);

            // Assert
            Assert.AreEqual(3, globalnyRejestrOperacji.Count);
            Assert.AreEqual(100, globalnyRejestrOperacji[1].Kwota);
            Assert.AreEqual("Wyp�ata �rodk�w", globalnyRejestrOperacji[1].Opis);
            Assert.AreEqual(50, globalnyRejestrOperacji[2].Kwota);
            Assert.AreEqual("Wyp�ata �rodk�w", globalnyRejestrOperacji[2].Opis);
        }

        [Test]
        [Category("WyplataEvent")]
        public void Wyplata_GlobalnyRejestrOperacji_WykonujeOperacjeFinansowaEvent_Clone()
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
            rachunek.Wyp�a�(100);

            // Assert
            Assert.IsFalse(senderTest == rachunek);
        }
    }
}
