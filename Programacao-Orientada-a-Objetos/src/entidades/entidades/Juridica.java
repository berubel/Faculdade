package entidades;

public class Juridica extends Pessoa
{	
	public int funcionarios;

	public Juridica(String tipo, String nome, float renda, float imposto, int funcionarios) 
	{
		super(tipo, nome, renda, imposto);
		this.funcionarios = funcionarios;
	}
	
	public void setFuncionarios(int funcionarios) {	this.funcionarios = funcionarios;}
	
	public int getFuncionarios() { return funcionarios;}
	
	public float calcularImposto(float renda)
	{
		float x;
		
		if (funcionarios < 10)
		{
			x = (renda * 16) / 100;
			imposto = x;
		}
		else
		{
			x = (renda * 14) / 100;
			imposto = x;
		}
		
		return imposto;
	}
}