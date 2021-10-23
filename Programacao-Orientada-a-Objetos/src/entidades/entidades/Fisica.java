package entidades;

public class Fisica extends Pessoa{
	
	public float saude;

	public Fisica(String tipo, String nome, float renda, float imposto, float saude) 
	{
		super(tipo, nome, renda, imposto);
		this.saude = saude;
	}
	
	public void setSaude(float saude) {  this.saude = saude; }
	public float getSaude() { return saude; }
	 
	public float calcularImposto(float renda)
	{
		 float x;
		 float y;
		 	
		if (renda < 20000)
		{		
			x = (renda * 15) / 100;
			y = (saude * 50) / 100;
			imposto =  x - y;
		}
		else
		{
			x = (renda * 25) / 100;
			y = (saude * 50) / 100;
			imposto =  x - y;
		}
		return imposto;
	}
}