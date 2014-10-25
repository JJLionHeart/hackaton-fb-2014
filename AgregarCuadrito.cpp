class NuevoElemento
void NuevoElemento :: AgregarElemento (cuadrito c)
{
	d = c.getDirect();
	elemento.setActivo(true);
	switch(d)
	{
		case 1: {
			elemento[n].setY(c.getY+1);
			elemento[n].setX(c.getX);
			elemento[n].setDire(d); 
			break;
		}
		case 2: {
			elemento[n].setY(c.getY);
			elemento[n].setX(c.getX-1);
			elemento[n].setDire(d);
			break;
		}
		case 3: {
			elemento[n].setY(c.getY+1);
			elemento[n].setX(c.getX);
			elemento[n].setDire(d);
			break;
		}
		case 4: {
			elemento[n].setX(c.getX+1);
			elemento[n].setY(c.getY);
			elemento[n].setDire(d);
			break;
		}
	}
}
if (bloque.getX() == cuadrado.getX() && bloque.getY() == cuadrito.getY())
{
	serpiente.AgregarElemento(cuadrito c)
}