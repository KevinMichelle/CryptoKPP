--Categorias que existen en el archivo
create table #categorias_actuales(
idCategoria int, categoria nvarchar(max))

insert into #categorias_actuales(idCategoria, categoria)
select actualCategoria, (CASE WHEN categoria IS NULL THEN '0' ELSE categoria END)
from (select distinct actualCategoria from(
select t1.codigoBarras, actualCategoria = t2.categoriaid
from zPtProducto t1
inner join dbo.tProductoTMP t2 on t2.codigodebarras = t1.codigoBarras)tabla)nuevatabla
left join dbo.tCategoriatmp categorias on categorias.categoriaid = nuevatabla.actualCategoria
order by actualCategoria


--Categorias que ya no existen en el archivo
create table #categorias_descartar(idCategoria int)

insert into #categorias_descartar(idCategoria)
select distinct t1.idCategoria from zPtCategoria t1
left join #categorias_actuales t2 on t2.idCategoria = t1.idCategoria
where t2.idCategoria IS NULL and t1.idCategoria > 0

--Codidos cuyas categorias no existen en el archivo
create table #productos_categoria_cero(codigoBarras bigint)

insert into #productos_categoria_cero
select codigoBarras from zPtProducto
where idCategoria in (select idCategoria from #categorias_descartar)

--Actualizar la categoria de los codigos anteriores a 0
update zPtProducto
	set idCategoria = 0
from zPtProducto
where codigoBarras in (select codigoBarras from #productos_categoria_cero)

--Y eliminar las categorias que ya no aparecen de la tabla ZPtCategoria
delete from dbo.zPtCategoria
where idCategoria in (select idCategoria from #categorias_descartar)

--Actualizar los codigos cuya categoria cambia
update zPtProducto
	set idCategoria = t2.categoriaid
from zPtProducto t1
inner join dbo.tProductoTMP t2 on t2.codigodebarras = t1.codigoBarras
where t1.idCategoria!= t2.categoriaid

--Insertar a zPtProductoCatFabMarIncidencias la incidencia de los cambios
declare @descripcion_cero nvarchar(max)
select @descripcion_cero = 
categoria from zPtCategoria where idCategoria = 0

insert into dbo.zPtProductoCatFabMarIncidencias(codigoBarras,
tipoIncidencia, anterior, anteriorDesc, remplazo, remplazoDesc, fecha)
select t1.codigoBarras, tipoIncidencia = 'CAT',
anterior = t2.idCategoria, anteriorDesc = t3.categoria,
remplazo = 0, remplazoDesc = @descripcion_cero, fecha = getdate()
from #productos_categoria_cero t1
inner join dbo.zPtProducto t2 on t2.codigoBarras = t1.codigoBarras
inner join dbo.zPtCategoria t3 on t3.idCategoria = t2.idCategoria

insert into dbo.zPtProductoCatFabMarIncidencias(codigoBarras,
tipoIncidencia, anterior, anteriorDesc, remplazo, remplazoDesc, fecha)
select t1.codigoBarras, tipoIncidencia = 'CAT',
anterior = t1.idCategoria, anteriorDesc = t3.categoria,
remplazo = t2.categoriaid, remplazoDesc = t4.categoria, fecha = getdate()
from zPtProducto t1
inner join dbo.tProductoTMP t2 on t2.codigodebarras = t1.codigoBarras
inner join dbo.zPtCategoria t3 on t3.idCategoria = t1.idCategoria
inner join dbo.tCategoriatmp t4 on t4.categoriaid = t2.categoriaid
where t1.idCategoria != t2.categoriaid