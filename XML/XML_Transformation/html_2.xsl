<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Игра</h1>
                <table border="5" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Кратко описание</th>
                        <th>Дата на пускане на пазара</th>
                        <th>Възрастово ограничение</th>
                        <th>Операционна система</th>  
                    </tr>         
                    <xsl:for-each select="game_library/game">
                        <tr>
                            <td>
                                <xsl:call-template name="game-name"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-summary"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-publish_date-date"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-age_restriction"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-operational_system-type"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="game-name">
        <xsl:value-of select="game_name/."/>
    </xsl:template>

    <xsl:template name="game-summary">
        <xsl:value-of select="summary/."/>
    </xsl:template>

    <xsl:template name="game-publish_date-date">
        <xsl:value-of select="publish_date/date/@year/."/>
    </xsl:template>

    <xsl:template name="game-age_restriction">
        <xsl:value-of select="age_restriction/."/>
    </xsl:template>

    <xsl:template name="game-operational_system-type">
        <xsl:value-of select="operational_system/@type/."/>
    </xsl:template>

</xsl:stylesheet>