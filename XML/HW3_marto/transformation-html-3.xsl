<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Производител</h1>
                <table border="3" align="center">
                    <tr>
                        <th>Тип</th>
                        <th>Град</th>
                        <th>Държава</th>
                    </tr>
                    <xsl:for-each select="board-game-store/game/publisher/headquarters">
                        <tr>
                            <td>
                                <xsl:call-template name="type"/>
                            </td>
                            <td>
                                <xsl:call-template name="city"/>
                            </td>
                            <td>
                                <xsl:call-template name="country"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="type">
        <xsl:value-of select="type/."/>
    </xsl:template>

    <xsl:template name="city">
        <xsl:value-of select="city/."/>
    </xsl:template>

    <xsl:template name="country">
        <xsl:value-of select="country/."/>
    </xsl:template>

</xsl:stylesheet>