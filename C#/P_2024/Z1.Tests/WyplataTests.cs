
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class WyplataTests
    {
        FieldInfo saldoRef = typeof(RachunekBankowy).GetField("saldo", BindingFlags.NonPublic | BindingFlags.Instance);

        [Test]
        [Category("Wyp³ata")]
        public void Wyp³ata_PoprawnaKwota_Wyp³ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            // Act
            var res = rachunek.Wp³aæ(100);
            rachunek.Wyp³aæ(100);

            // Assert
            decimal saldoKoñcowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(0, saldoKoñcowe);
            Assert.IsTrue(res);
        }

        [Test]
        [Category("Wyp³ata")]
        public void Wyp³ata_NiepoprawnaKwota_B³¹dBrakuŒrodków()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal saldoPocz¹tkowe = (decimal)saldoRef.GetValue(rachunek);
            decimal kwota = 1000;

            // Act
            var res = rachunek.Wyp³aæ(kwota);

            // Assert
            decimal saldoKoñcowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(saldoPocz¹tkowe, saldoKoñcowe);
            Assert.IsFalse(res);
        }

        [Test]
        [Category("Wyp³ata")]
        public void Wyp³ata_NiepoprawnaKwota_B³¹dPróbaWyp³atyZaPomoc¹UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal saldoPocz¹tkowe = (decimal)saldoRef.GetValue(rachunek);
            decimal kwota = -50;

            // Act
            var res = rachunek.Wyp³aæ(kwota);

            // Assert
            decimal saldoKoñcowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(saldoPocz¹tkowe, saldoKoñcowe);
            Assert.IsFalse(res);
        }
    }
}
