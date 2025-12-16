function onEdit(e) {

  const libro = e.source;
  const hoja = libro.getActiveSheet();
  const celdaActiva = e.range;

  const NOMBRE_HOJA = "Hoja 1";
  const COLUMNA_DESPLEGABLE = 2; // Columna B
  const COLUMNA_EMAIL = 1;      // Columna A

  // 1. Verificar que la edición sea en la hoja correcta, columna B y valor "Enviar"
  if (hoja.getName() === NOMBRE_HOJA &&
      celdaActiva.getColumn() === COLUMNA_DESPLEGABLE &&
      celdaActiva.getValue() === "Enviar") {

    const fila = celdaActiva.getRow();
   
    // 2. Gestión de Destinatarios (Ejemplos)
    const email = hoja.getRange(fila, COLUMNA_EMAIL).getValue();
   
    // Destinatarios principales (Para)
    const mailsTotal = email + "," + "ejemplo.correo1@ejemplo.com" + "," + "ejemplo.correo2@ejemplo.es";
   
    // Destinatarios en copia (CC)
    const mailsCopia = "correo.ejemplo1@ejemplo.es" + "," + " correo.ejemplo2@ejemplo.es ";

    // 3. Obtener y formatear datos de la fila
    const name= hoja.getRange(fila, 30).getValue();
 
    const asunto = "Escribir asunto aquí";

    // 4. Cargar la plantilla HTML desde Google Drive
    // ID del archivo HTML en Drive
    const idArchivoHtml = "Al compartir el Drive, te aparece el ID";
    let cuerpoHtml = getTemplate(idArchivoHtml);

    // 5. Reemplazar las etiquetas dinámicas por los datos reales de la tabla
    cuerpoHtml = cuerpoHtml.replace("{{name}}", name)
                           
    // 6. Ejecución: Crear el borrador en Gmail
    if (email !== "") {
  //En este caso, el cuerpo del correo se realizará con un HTML que se cargará desde el DRIVE, pero se puede escribir directamente aquí.
      GmailApp.createDraft(mailsTotal, asunto, "", {
        htmlBody: cuerpoHtml,
        cc: mailsCopia
      });
     
      // Notificación de éxito en la interfaz de la hoja de cálculo
      SpreadsheetApp.getUi().alert("✅ Borrador creado con éxito para: " + email);
    } else {
      SpreadsheetApp.getUi().alert("⚠️ Error: No hay un correo electrónico en la columna A.");
    }
  }
}

/**
 * Función auxiliar para extraer el contenido del archivo HTML en Drive
 */
function getTemplate(htmlId) {
  const file = DriveApp.getFileById(htmlId);
  return file.getBlob().getDataAsString();
}