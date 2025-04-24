# Fecha apenas janelas de pastas do Explorador de Arquivos

$shell = New-Object -ComObject Shell.Application

$shell.Windows() | ForEach-Object {
    try {
        if ($_.FullName -like '*explorer.exe') {
            $_.Quit()
        }
    } catch {
        # Silencia qualquer erro (ex: janelas que não podem ser fechadas)
    }
}