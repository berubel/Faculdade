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
	
	public static void main(String[] args) 
	{	 
		Scanner sc = new Scanner(System.in);
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
			System.out.println("\n\nResposta: ");
		
			op = sc.nextInt();
			
			switch (op) 
			{
				case 1:
					
					do
					{
						System.out.println("\n\nÉ um contribuinte: \n1 - Pessoa Fisica \n2 - Pessoa Juridica: \n\nResposta: ");
						opc = sc.nextInt();
						
						if(opc > 2 || opc < 1) 
						{
							System.out.println("\n\nOpção Invalida! Digite novamente");	
						}	
					}while(opc > 2 || opc < 1);	
					
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
									System.out.println("\n\nDigite os gastos com saude do contribuinte: ");
									saude = sc.nextFloat();
				
									tipo = new String("Pessoa Fisica");
									pessoaF.setNome(nome);
									pessoaF.setRenda(renda);
									pessoaF.setSaude(saude);
									pessoaF.setTipo(tipo);
									imposto = pessoaF.calcularImposto(renda);
									
									System.out.println("\n\nImposto = " + imposto);
									
									Fisica vetorPF [] = new Fisica[N];
									vetorPF[i] = new Fisica(tipo, nome, renda, imposto, saude);
									listaPF.add(vetorPF[i]);
							
								}
								else if (opc == 2)
								{
								
									System.out.println("\n\nDigite o numero de funcionarios: ");
									funcionarios = sc.nextInt();
									tipo = new String("Pessoa Juridica");
									pessoaJ.setNome(nome);
									pessoaJ.setRenda(renda);
									pessoaJ.setFuncionarios(funcionarios);
									pessoaJ.setTipo(tipo);
									imposto = pessoaJ.calcularImposto(renda);
									
									System.out.println("\n\nImposto = " + imposto);
									
									Juridica vetorPJ [] = new Juridica[N];
									vetorPJ[i] = new Juridica(tipo, nome, renda, imposto, funcionarios);
									listaPJ.add(vetorPJ[i]);
								}	
								
							}while(opc > 2 || opc < 1);
						}	
								
				break;
					
				case 2:
					do
					{
						System.out.println("\n\nÉ um contribuinte: \n1 - Pessoa Fisica \n2 - Pessoa Juridica: \n\nResposta: ");
						opc = sc.nextInt();
						
						if(opc > 2 || opc < 1) 
						{
							System.out.println("\n\nOpção Invalida! Digite novamente");	
						}	
						
					}while(opc > 2 || opc < 1);	
					
					do 
					{
						System.out.println("\nDigite o índice do contribuinte (inicia do 0): ");
						id = sc.nextInt();
						if(id > listaPF.size() || id > listaPJ.size())
						{
							System.out.println("\n\nIndice fora dos limites da lista! Digite novamente");	
						}
					}while(id > listaPF.size() || id > listaPJ.size());
					
					if (opc == 1)
					{
						System.out.println("\n\nContribuinte nº " + id);
						System.out.println("\nTipo: " + listaPF.get(id).tipo);
						System.out.println("\nNome: " + listaPF.get(id).nome);
						System.out.println("\nRenda: " + listaPF.get(id).renda);
						System.out.println("\nGasto com saude: R$ " + listaPF.get(id).saude);
						System.out.println("\nImposto: R$ " + listaPF.get(id).imposto);
					} 
					else
					{
						System.out.println("\n\nContribuinte nº " + id);
						System.out.println("\nTipo: " + listaPJ.get(id).tipo);
						System.out.println("\nNome: " + listaPJ.get(id).nome);
						System.out.println("\nRenda: " + listaPJ.get(id).renda);
						System.out.println("\nNumero de funcionarios: " + listaPJ.get(id).funcionarios);
						System.out.println("\nImposto: R$ " + listaPJ.get(id).imposto);		
					}	
				break;
				
				case 3:
					
					do
					{
						System.out.println("\n\nDeseja ver a lista de contribuintes: \n1 - Pessoa Fisica \n2 - Pessoa Juridica: \n\nResposta: ");
						opc = sc.nextInt();
						
						if(opc > 2 || opc < 1) 
						{
							System.out.println("\n\nOpção Invalida! Digite novamente");	
						}	
					}while(opc > 2 || opc < 1);	
						
					System.out.println("\nLista de contribuintes: " );
					
					if (opc == 1)
					{
						for (i=0; i<listaPF.size(); i++)
						{
							System.out.println("\n\nContribuinte nº " + i);
							System.out.println("\nTipo: " + listaPF.get(i).tipo);
							System.out.println("\nNome: " + listaPF.get(i).nome);
							System.out.println("\nRenda: " + listaPF.get(i).renda);
							System.out.println("\nGasto com saude: " + listaPF.get(i).saude);
							System.out.println("\nImposto:  " + listaPF.get(i).imposto);
						}
					} 
					else 
					{
						for (i=0; i<listaPJ.size(); i++)
						{
							System.out.println("\n\nContribuinte nº " + i);
							System.out.println("\nTipo: " + listaPJ.get(i).tipo);
							System.out.println("\nNome: " + listaPJ.get(i).nome);
							System.out.println("\nRenda: " + listaPJ.get(i).renda);
							System.out.println("\nNumero de funcionarios: " + listaPJ.get(i).funcionarios);
							System.out.println("\nImposto: R$ " + listaPJ.get(i).imposto);		
						}
					}		
				break;
				
				case 4:

					do
					{
						System.out.println("\n\nDeseja remover um contribuinte: \n1 - Pessoa Fisica \n2 - Pessoa Juridica: \n\nResposta: ");
						opc = sc.nextInt();
						
						if(opc > 2 || opc < 1) 
						{
							System.out.println("\n\nOpção Invalida! Digite novamente");	
						}	
						
					}while(opc > 2 || opc < 1);	
					
						do 
						{
							System.out.println("\nDigite o índice do contribuinte (inicia do 0): ");
							id = sc.nextInt();
							if(id > listaPF.size() || id > listaPJ.size())
							{
								System.out.println("\n\nIndice fora dos limites da lista! Digite novamente");	
							}
						}while(id > listaPF.size() || id > listaPJ.size());
						
						if (listaPF ==  null || listaPJ == null)
						{
							System.out.println("\n\nLista Vazia! Impossivel realizar exclusao");	
						} 
						else if (opc == 1)
						{
							listaPF.remove(id);
							System.out.println("\nRemovido com sucesso! ");
						} 
						else 
						{
							listaPJ.remove(id);
							System.out.println("\nRemovido com sucesso! ");
						}	
					
				break;
				
				case 5:
					
					do
					{
						System.out.println("\n\nDeseja deletar a lista de contribuinte: \n1 - Pessoa Fisica \n2 - Pessoa Juridica: \n\nResposta: ");
						opc = sc.nextInt();
						
						if(opc > 2 || opc < 1) 
						{
							System.out.println("\n\nOpção Invalida! Digite novamente");	
						}	
						
					}while(opc > 2 || opc < 1);	
					
						if (listaPF ==  null || listaPJ == null)
						{
							System.out.println("\n\nLista Vazia! Impossivel realizar exclusao");	
						} 
						else if (opc == 1)
						{
							listaPF.removeAll(listaPF);
							System.out.println("\nRemovido com sucesso! ");
						}
						else
						{
							listaPJ.removeAll(listaPJ);
							System.out.println("\nRemovido com sucesso! ");
						}

				break;
				
			default:
				
				System.out.println("\n\nOpção inválida!!");
			}	
			do
			{
				System.out.println("\n\nDeseja realizar nova operação?\n1 - SIM; \n2 - NAO\n\nResposta:");
				op = sc.nextInt();
				if (op < 1 || op > 2)
				{
					System.out.println("Opcao Invalida! Digite novamente");
				}
			}while (op < 1 || op > 2);
			
		}while (op == 1);
	}
}
