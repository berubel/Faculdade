package entidades;
import java.lang.Math;

public class Pessoa 
{
	public float renda;
	public String nome;
	public float imposto;
	public String tipo;

	public Pessoa(String tipo, String nome, float renda, float imposto) 
	{
		this.tipo = tipo;
		this.nome = nome;
		this.renda = renda;
		this.imposto = imposto;
		
	}
	
	public String getTipo() { return tipo; }
    public void setTipo(String tipo) { this.tipo = tipo; } 

	public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; } 
    
    public float getRenda() { return renda; }
    public void setRenda(float Renda) { this.renda = renda; }
    
    public double getImposto() { return imposto; }
    public void setImposto(float imposto) { this.imposto = imposto; }
    
    
}

