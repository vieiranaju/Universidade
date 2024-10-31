/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Lista_06.Snake;

/**
 *
 * @author vieir
 */
public class SnakeHandler 
{
    private Snake snake;
	public void setSnake(Snake snake) {this.snake = snake; }

	public static void main(String[] args){
		new SnakeHandler().setSnake(new Snake());
	}
}
