package entidades;

import java.util.Locale;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

import entidades.Fisica;
import entidades.Juridica;
import entidades.Pessoa;

/*
 * TRABALHO 2ºVA Programação Orientada a Objetos:
 * 
 * Alunos: 2010840 - Gabriele Cardoso das Virgens
 * 		   2011321 - João Cândido de Jesus Neto
 */

public class Aplicacao
{
	static int N;
	static int id;
	
	static Scanner sc = new Scanner(System.in);
	
	public static int obterTipoPessoa()
	{
		int opc;
		do
		{
			opc = sc.nextInt();
			if(opc > 2 || opc < 1) 
			{
				System.out.println("\n\nOpção Inválida! Digite novamente");	
			}	
		}while(opc > 2 || opc < 1);	
		
		return opc;
	}
	public static void printPessoaFisica(List<Fisica> listaPF, int id)
	{
		System.out.println("\n\nContribuinte nº " + id);
		System.out.println("\nTipo: " + listaPF.get(id).tipo);
		System.out.println("\nNome: " + listaPF.get(id).nome);
		System.out.println("\nRenda: R$ " + listaPF.get(id).renda);
		System.out.println("\nGasto com saúde: R$ " + listaPF.get(id).saude);
		System.out.println("\nImposto: R$ " + listaPF.get(id).imposto);	
	}
	public static void printPessoaJuridica(List<Juridica> listaPJ, int id)
	{
		System.out.println("\n\nContribuinte nº " + id);
		System.out.println("\nTipo: " + listaPJ.get(id).tipo);
		System.out.println("\nNome: " + listaPJ.get(id).nome);
		System.out.println("\nRenda: R$ " + listaPJ.get(id).renda);
		System.out.println("\nNumero de funcionários: " + listaPJ.get(id).funcionarios);
		System.out.println("\nImposto: R$ " + listaPJ.get(id).imposto);		
	}
	public static boolean seListaVazia(List<Fisica> listaPF, List<Juridica> listaPJ, int opc)
	{
		boolean vazia = false;
		
		if ((listaPF.isEmpty() == true && opc == 1) || (listaPJ.isEmpty() == true && opc == 2))
		{
			System.out.println("\n\nLista Vazia!");
			vazia = true;
		}
		return vazia; 	
	}
	public static int obterIndicePessoa(List<Fisica> listaPF, List<Juridica> listaPJ, int opc)
	{		
		do
		{
			System.out.println("\nDigite o índice do contribuinte (inicia do 0): ");
			id = sc.nextInt();
			
			if((id >= listaPF.size() && opc == 1) || (id >= listaPJ.size() && opc == 2))
			{
				System.out.println("\n\nÍndice fora dos limites da lista! Digite novamente");	
			}
		}while((id >= listaPF.size() && opc == 1) || (id >= listaPJ.size() && opc == 2) );
		
		return id;
	}
	public static void printImpostoTotal(int opc, float impostoF, float impostoJ)
	{
		if (opc == 1)
		{
			System.out.println("\n\nImposto total arrecadado por pessoas físicas: R$ " + impostoF);
		}
		else 
		{
			System.out.println("\n\nImposto total arrecadado por pessoas Jurídicas: R$ " + impostoJ);
		}
	}
	public static void main(String[] args) 
	{	 
		Locale.setDefault(Locale.US);
		
		Fisica pessoaF;
		Juridica pessoaJ;
		
		List<Fisica> listaPF = new ArrayList<Fisica>();
		List<Juridica> listaPJ = new ArrayList<Juridica>();
		
		int op, opc, i;
		String nome;
		String tipo;
		float imposto;
		float renda, saude;
		int funcionarios;
		float impostoTotalF = 0, impostoTotalJ = 0;
		float impostoArrecadado;
		
		pessoaF = new Fisica(null, null, 0, 0, 0);
		pessoaJ = new Juridica(null, null, 0, 0, 0);
		
		do
		{	
			System.out.println("Menu: ");
			System.out.println("\n1 - Adicionar contribuinte ");
			System.out.println("\n2 - Ver contribuinte ");
			System.out.println("\n3 - Ver lista de contribuintes  ");
			System.out.println("\n4 - Remover  contribuinte");
			System.out.println("\n5 - Deletar toda lista");
			System.out.println("\n6 - Ver imposto total arrecadado");
			System.out.println("\n\nResposta: ");
		
			op = sc.nextInt();
			
			switch (op) 
			{
				case 1:
					
					System.out.println("\n\nÉ um contribuinte: \n1 - Pessoa Física \n2 - Pessoa Jurídica: \n\nResposta: ");
					opc = obterTipoPessoa();	
					
					System.out.println("\n\nDigite o número de contribuintes a serem inseridos: ");
					N = sc.nextInt(); 
						
					for(i = 0; i < N; i++)
					{		
						do 
						{
							System.out.println("\n\nDigite o nome do contribuinte: ");
							nome = sc.next();
							System.out.println("\n\nDigite a renda do contribuinte: ");
							renda = sc.nextFloat();
						
							if(opc == 1) 
							{
								System.out.println("\n\nDigite os gastos com saúde do contribuinte: ");
								saude = sc.nextFloat();
				
								tipo = new String("Pessoa Física");
								pessoaF.setNome(nome);
								pessoaF.setRenda(renda);
								pessoaF.setSaude(saude);
								pessoaF.setTipo(tipo);
								imposto = pessoaF.calcularImposto(renda);
									
								System.out.println("\n\nImposto = R$ " + imposto);
									
								Fisica vetorPF [] = new Fisica[N];
								vetorPF[i] = new Fisica(tipo, nome, renda, imposto, saude);
								listaPF.add(vetorPF[i]);
								impostoTotalF += imposto;
							
							}
							else if (opc == 2)
							{
								System.out.println("\n\nDigite o número de funcionários: ");
								funcionarios = sc.nextInt();
								tipo = new String("Pessoa Jurídica");
								pessoaJ.setNome(nome);
								pessoaJ.setRenda(renda);
								pessoaJ.setFuncionarios(funcionarios);
								pessoaJ.setTipo(tipo);
								imposto = pessoaJ.calcularImposto(renda);
									
								System.out.println("\n\nImposto = R$ " + imposto);
									
								Juridica vetorPJ [] = new Juridica[N];
								vetorPJ[i] = new Juridica(tipo, nome, renda, imposto, funcionarios);
								listaPJ.add(vetorPJ[i]);
								impostoTotalJ += imposto;
							}	
								
						}while(opc > 2 || opc < 1);
						
						printImpostoTotal(opc, impostoTotalF, impostoTotalJ);
					}	
								
				break;
					
				case 2:
					
					System.out.println("\n\nÉ um contribuinte: \n1 - Pessoa Física \n2 - Pessoa Jurídica: \n\nResposta: ");
					opc = obterTipoPessoa();	
					
					if(seListaVazia( listaPF, listaPJ, opc) == true)
					{	}
					else 
					{
						obterIndicePessoa(listaPF, listaPJ, opc);
					
						if (opc == 1)
						{
							printPessoaFisica(listaPF, id);
						} 
						else
						{
							printPessoaJuridica(listaPJ, id);
						}	
					}
					
				break;
				
				case 3:
						
					System.out.println("\n\nDeseja ver a lista de contribuintes: \n1 - Pessoa Física \n2 - Pessoa Jurídica: \n\nResposta: ");
					opc = obterTipoPessoa();	
					
					if(seListaVazia( listaPF, listaPJ, opc) == true)
					{	}
					else 
					{
						System.out.println("\nLista de contribuintes: " );
						
						if (opc == 1)
						{
							for (i=0; i<listaPF.size(); i++)
							{
								printPessoaFisica(listaPF, i);
							}
						}
						else 
						{
							for (i=0; i<listaPJ.size(); i++)
							{
								printPessoaJuridica(listaPJ, i);
							}
						}
						printImpostoTotal(opc, impostoTotalF, impostoTotalJ);
					}
					
				break;
				
				case 4:

					System.out.println("\n\nDeseja remover um contribuinte: \n1 - Pessoa Física \n2 - Pessoa Jurídica: \n\nResposta: ");
					opc = obterTipoPessoa();
						
					if (seListaVazia( listaPF, listaPJ, opc) == true)
					{
						System.out.println("\nImpossível realizar exclusão!");
					}
					else 
					{
						obterIndicePessoa(listaPF, listaPJ, opc);
						if (opc == 1)
						{
							impostoTotalF -= listaPF.get(id).imposto;
							listaPF.remove(id);
							System.out.println("\nRemovido com sucesso! ");	
						} 
						else 
						{
							impostoTotalJ -= listaPJ.get(id).imposto;
							listaPJ.remove(id);
							System.out.println("\nRemovido com sucesso! ");
						}	
					}		
					
				break;
				
				case 5:
					
					System.out.println("\n\nDeseja deletar a lista de contribuinte: \n1 - Pessoa Física \n2 - Pessoa Jurídica: \n\nResposta: ");
					opc = obterTipoPessoa();	
					
					if (seListaVazia( listaPF, listaPJ, opc) == true)
					{
						System.out.println("\nImpossível realizar exclusão!");
					}
					else if (opc == 1)
					{
						impostoTotalF = 0;
						listaPF.removeAll(listaPF);
						System.out.println("\nRemovido com sucesso! ");
					}
					else
					{
						impostoTotalJ = 0;
						listaPJ.removeAll(listaPJ);
						System.out.println("\nRemovido com sucesso! ");
					}

				break;
				
				case 6:
					
						System.out.println("\n\nImpostos arrecadados");
						System.out.println("\n\nPessoas físicas: R$ " + impostoTotalF);
						System.out.println("\nPessoas jurídicas: R$ " + impostoTotalJ);
						impostoArrecadado = impostoTotalF + impostoTotalJ;
						System.out.println("\n\nImposto total arrecadado: R$ " + impostoArrecadado);
						
				break;
				
			default:
				
				System.out.println("\n\nOpção inválida!!");
			}	
			do
			{
				System.out.println("\n\nDeseja realizar nova operação?\n1 - SIM; \n2 - NÃO\n\nResposta:");
				op = sc.nextInt();
				if (op < 1 || op > 2)
				{
					System.out.println("Opção Inválida! Digite novamente");
				}
			}while (op < 1 || op > 2);
			
		}while (op == 1);
	}
}
